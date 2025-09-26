# verificar_base.py
import pandas as pd

try:
    # Carregar dados
    dados = pd.read_csv('data/base_de_dados.csv', sep=';', encoding='utf-8-sig')
    
    print("=== VERIFICAÇÃO DA BASE DE DADOS ===")
    print(f"Total de registros: {len(dados)}")
    
    print("\nÚltimos 3 registros:")
    print(dados.tail(3))
    
    print("\nDistribuição das cargas de estudo:")
    distribuicao = dados['Carga de Estudo Recomendada (h/dia)'].value_counts().sort_index()
    print(distribuicao)
    
    # Verificar se temos pelo menos 2 por categoria
    print("\nCategorias com pelo menos 2 registros:")
    for carga, quantidade in distribuicao.items():
        status = "OK" if quantidade >= 2 else "PROBLEMA"
        print(f"{carga}h: {quantidade} registros {status}")
        
except Exception as e:
    print(f"Erro: {e}")