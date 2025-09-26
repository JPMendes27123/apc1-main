import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.naive_bayes import GaussianNB
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, f1_score, confusion_matrix, classification_report, precision_score, recall_score
from preprocessamento import carregar_e_preprocessar_dados
import os

def treinar_modelos():
    
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
    
    print(f"Treino: {X_treino.shape[0]}, Teste: {X_teste.shape[0]}")
    
    modelos = {
        'SVM': SVC(random_state=42),
        'Naive Bayes': GaussianNB(),
        'Arvore de Decisao': DecisionTreeClassifier(random_state=42)
    }
    
    resultados = []
    
    for nome, modelo in modelos.items():
        print(f"\n{nome}")
        
        modelo.fit(X_treino, y_treino)
        y_previsto = modelo.predict(X_teste)
        
        acuracia = accuracy_score(y_teste, y_previsto)
        f1 = f1_score(y_teste, y_previsto, average='weighted')
        precisao = precision_score(y_teste, y_previsto, average='weighted', zero_division=0)
        recall = recall_score(y_teste, y_previsto, average='weighted', zero_division=0)
        
        resultados.append({
            'Modelo': nome,
            'Acuracia': acuracia,
            'F1_Score': f1,
            'Precisao': precisao,
            'Recall': recall
        })
        
        print(f"Acuracia: {acuracia:.3f}")
        print(f"F1-Score: {f1:.3f}")
        print(f"Precisao: {precisao:.3f}")
        print(f"Recall: {recall:.3f}")
        print(f"Matriz de Confusao:\n{confusion_matrix(y_teste, y_previsto)}")
    
    resultados_df = pd.DataFrame(resultados)
    resultados_df.to_csv('results/resultados_modelos.csv', index=False)
    print("Resultados salvos: 'results/resultados_modelos.csv'")
    
    return resultados_df

if __name__ == "__main__":
    os.makedirs('results', exist_ok=True)
    print("=== MACHINE LEARNING - EQUILIBRA ===")
    resultados = treinar_modelos()
    print("Analise concluida!")