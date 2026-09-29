# ⚡ Controle de Consumo de Energia (CRUD)

Projeto desenvolvido para a P1 da disciplina de **Algoritmo e Estrutura de Dados**. 
Trata-se de um sistema CRUD em C que permite ao usuário gerenciar e calcular o consumo mensal e anual de energia elétrica.

## 👥 Discentes
* **Fernanda Sousa de Assunção Vale** - Matrícula: 20250071607
* **Luiz Ruifeng Mei** - Matrícula: 20240006006

## ⚙️ Funcionalidades
O sistema implementa o conceito de CRUD (Create, Read, Update, Delete) aliado a funções de cálculo financeiro:

1. **Cadastrar Consumo Mensal (Create):** Registra o gasto (em kWh) de um mês específico (1 a 12). O sistema impede a sobrescrita acidental de um mês já registrado e recusa valores negativos.
2. **Buscar Consumo por Mês (Read):** Exibe o consumo de um mês cadastrado. A lógica diferencia corretamente um mês onde não houve consumo (0 kWh) de um mês que ainda não foi cadastrado no sistema (valor -1).
3. **Atualizar Consumo do Mês (Update):** Permite alterar o consumo em kWh de um mês previamente registrado.
4. **Deletar Consumo do Mês (Delete):** Remove o consumo de um mês específico, retornando o slot para o status de "não cadastrado".
5. **Calcular Custo (Calculate):** 
   * **Mensal:** Calcula a estimativa de custo multiplicando o gasto do mês selecionado pela tarifa informada.
   * **Anual:** Soma o consumo do mês 1 até o mês atual informado pelo usuário e calcula o custo total. Exige que todos os meses do período solicitado estejam previamente cadastrados.
   * *Segurança:* O sistema possui um mecanismo de limpeza de buffer que alerta o usuário e evita quebras caso tarifas ou meses sejam digitados com vírgula (`,`) ao invés de ponto (`.`).
