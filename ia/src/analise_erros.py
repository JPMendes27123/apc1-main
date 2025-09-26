import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
from preprocessamento import carregar_e_preprocessar_dados
import os

def analisar_erros_classificacao():
    print("=== ANALISE DETALHADA DOS ERROS ===")
    
    X_scaled, y, scaler, dados = carregar_e_preprocessar_dados()
    
    def categorizar_carga(horas):
        if horas <= 2: return 'Muito_Baixa'
        elif horas <= 4: return 'Baixa'
        elif horas <= 6: return 'Moderada'
        else: return 'Alta'
    
    y_categorico = y.apply(categorizar_carga)
    
    X_treino, X_teste, y_treino, y_teste = train_test_split(
        X_scaled, y_categorico, test_size=0.2, random_state=42
    )
    
    print(f"Dados de teste: {len(X_teste)} registros")
    print(f"Distribuicao real: {y_teste.value_counts().to_dict()}")
    
    modelos = {
        'Naive Bayes': GaussianNB(),
        'SVM': SVC(random_state=42),
        'Arvore de Decisao': DecisionTreeClassifier(random_state=42)
    }
    
    for nome, modelo in modelos.items():
        print(f"\n{nome.upper()}")
        
        modelo.fit(X_treino, y_treino)
        y_previsto = modelo.predict(X_teste)
        
        acuracia = accuracy_score(y_teste, y_previsto)
        print(f"Acuracia: {acuracia:.3f}")
        
        print(f"Matriz de Confusao - {nome}:")
        matriz = confusion_matrix(y_teste, y_previsto)
        categorias = y_teste.unique()

        header = "Real \\ Previsto".ljust(15) + "".join([cat.ljust(12) for cat in categorias])
        print(header)
        print("-" * len(header))

        for i, cat_real in enumerate(categorias):
            linha = f"{cat_real:<15}"
            for j in range(len(categorias)):
                linha += f"{matriz[i][j]:<12}"
            print(linha)
        
        print(f"Relatorio de Classificacao:")
        print(classification_report(y_teste, y_previsto))
        
        resultados = pd.DataFrame({
            'Real': y_teste,
            'Previsto': y_previsto,
            'Estresse': dados.loc[y_teste.index, 'Estresse'],
            'Sono': dados.loc[y_teste.index, 'Sono (horas/noite)'],
            'Prova': dados.loc[y_teste.index, 'Proximidade da Prova (dias)'],
            'Carga_Real': dados.loc[y_teste.index, 'Carga de Estudo Recomendada (h/dia)']
        })
        resultados['Acertou'] = resultados['Real'] == resultados['Previsto']
        resultados['Tipo_Erro'] = resultados.apply(
            lambda x: f"{x['Real']} -> {x['Previsto']}" if x['Real'] != x['Previsto'] else "Acerto", 
            axis=1
        )
        
        erros = resultados[resultados['Acertou'] == False]
        if len(erros) > 0:
            print(f"{len(erros)} ERROS ENCONTRADOS:")
            print(erros[['Real', 'Previsto', 'Estresse', 'Sono', 'Prova', 'Carga_Real']])
            
            padroes_erro = erros['Tipo_Erro'].value_counts()
            print(f"PADROES DOS ERROS:")
            for padrao, quantidade in padroes_erro.items():
                print(f"  {padrao}: {quantidade} vez(es)")

def criar_relatorio_final():
    print("\n" + "="*70)
    print("RELATORIO FINAL - INFORMACOES PARA O RELATORIO")
    print("="*70)
    
    X_scaled, y, scaler, dados = carregar_e_preprocessar_dados()
    
    print("\nCORRELACOES ENTRE VARIAVEIS:")
    correlacoes = dados[['Estresse', 'Sono (horas/noite)', 'Proximidade da Prova (dias)', 
                        'Carga de Estudo Recomendada (h/dia)']].corr()
    print(correlacoes)
    
    print("\nINFORMACOES PARA AS CONCLUSOES:")
    print("1. Variaveis mais influentes na carga de estudo:")
    print("2. Padroes comuns nos erros dos modelos:")
    print("3. Sugestoes para melhorar a coleta de dados:")
    print("4. Recomendacoes para modelos futuros:")

if __name__ == "__main__":
    os.makedirs('results', exist_ok=True)
    
    analisar_erros_classificacao()
    criar_relatorio_final()
    
    print("\nAnalise de erros concluida!")