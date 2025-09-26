import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler

def carregar_e_preprocessar_dados():
    
    dados = pd.read_csv('data/base_de_dados.csv', sep=';', encoding='utf-8-sig')
    print("Dados CSV carregados")
    
    dados_processed = dados.copy()
    
    dados_processed['Estresse'] = dados_processed['Estresse'].clip(lower=0, upper=10)
    dados_processed['Sono (horas/noite)'] = dados_processed['Sono (horas/noite)'].clip(lower=0, upper=10)
    dados_processed['Proximidade da Prova (dias)'] = dados_processed['Proximidade da Prova (dias)'].clip(lower=0, upper=30)
    
    print("Dados faltantes:")
    print(dados_processed.isnull().sum())
    
    X = dados_processed[['Estresse', 'Sono (horas/noite)', 'Proximidade da Prova (dias)']]
    y = dados_processed['Carga de Estudo Recomendada (h/dia)']
    
    scaler = StandardScaler()
    X_scaled = scaler.fit_transform(X)
    
    print(f"Features normalizadas: {X_scaled.shape}")
    print(f"Target: {y.shape}")
    
    return X_scaled, y, scaler, dados_processed

def explorar_dados(dados):
    print("ESTATISTICAS DESCRITIVAS:")
    print(dados[['Estresse', 'Sono (horas/noite)', 'Proximidade da Prova (dias)', 
                 'Carga de Estudo Recomendada (h/dia)']].describe())

if __name__ == "__main__":
    X_scaled, y, scaler, dados = carregar_e_preprocessar_dados()
    explorar_dados(dados)