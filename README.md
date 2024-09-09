# Projeto de Monitoramento com ThingSpeak e Google Sheets

Este projeto demonstra como utilizar o sensor MQ-9 para monitorar gases e integrar os dados com o ThingSpeak e Google Sheets. Os dados são visualizados em um gráfico em um site hospedado.

## Etapas do Projeto

### 1. Configuração do Hardware

1. **Componentes Necessários:**
   - ESP8266
   - Sensor MQ-9
   - Buzzer
   - LED

2. **Esquema de Ligação:**
   - Conecte o pino de leitura do sensor MQ-9 ao pino analógico A0 do ESP8266.
   - Conecte o buzzer ao pino digital D2.
   - Conecte o LED ao pino digital D1.

3. Configuração do ThingSpeak
Criar uma Conta e Canal:

Acesse ThingSpeak e crie uma conta.
Crie um canal e anote o Channel ID e a API Key de escrita.
Configurar Campos:

Configure um campo para receber os dados do sensor.

4. Integração com Google Sheets
Publicar a Planilha:

No Google Sheets, vá para Arquivo > Publicar na web.
Escolha a aba ou planilha e copie o link gerado.
Criar uma Planilha para Armazenar Dados:

Configure a planilha para receber dados do ThingSpeak.

5. Google Sites
No Google sites, apenas inseri um gráfico que é feito no proprio Google Sheets

Conclusão
Este projeto ilustra a integração de sensores com a nuvem e a visualização de dados em tempo real usando ThingSpeak e Google Sheets. É uma base sólida para projetos de IoT e análise de dados em tempo real.
