
GitHub Copilot: # 📦 Cube - Projeto 42

Um motor de raycasting 3D inspirado no clássico Wolfenstein 3D, desenvolvido em C usando a biblioteca miniLibX.

## 🎯 Objetivo

Criar um "jogo" 3D onde o jogador pode navegar através de um labirinto renderizado em tempo real usando técnicas de raycasting. O projeto simula uma visão em primeira pessoa com paredes texturizadas, movimentação fluida e rotação da câmera.

## 📋 Funcionalidades Principais

- ✅ Renderização 3D em tempo real usando raycasting
- ✅ Movimentação suave do jogador (WASD)
- ✅ Rotação da câmera (setas direcionais ou mouse)
- ✅ Texturas diferentes para paredes norte/sul e leste/oeste
- ✅ Cores diferentes para chão e teto
- ✅ Sistema de colisão com paredes
- ✅ Leitura de mapas a partir de arquivos .cub
- ✅ Gerenciamento adequado de janela e eventos

## 🗂️ Estrutura do Projeto

```
cube/
├── src/
│   ├── main.c
│   ├── parsing/
│   ├── raycasting/
│   ├── graphics/
│   ├── player/
│   └── utils/
├── includes/
├── maps/
├── textures/
├── libft/
├── Makefile
└── README.md
```

---

# 📊 DIVISÃO DE TAREFAS PARA TRELLO

## 👤 **PESSOA 1 - CORE ENGINE & RAYCASTING**

### 🔧 **Setup & Estrutura Base**
- [ ] Configurar Makefile com todas as flags obrigatórias
- [ ] Criar estrutura de diretórios do projeto
- [ ] Integrar libft ao projeto
- [ ] Configurar miniLibX e testar compilação básica
- [ ] Criar headers principais (cube.h, structs.h)

### 🎮 **Sistema de Raycasting**
- [ ] Implementar algoritmo DDA (Digital Differential Analyzer)
- [ ] Calcular distâncias dos raios até as paredes
- [ ] Implementar projeção de paredes na tela
- [ ] Corrigir efeito "fisheye" nas distâncias
- [ ] Otimizar performance do raycasting

### 🖼️ **Sistema de Renderização**
- [ ] Criar sistema de buffer de imagem
- [ ] Implementar renderização de paredes verticais
- [ ] Calcular altura das paredes baseada na distância
- [ ] Renderizar chão e teto com cores sólidas
- [ ] Implementar sistema de frames por segundo

### 🎨 **Sistema de Texturas**
- [ ] Carregar texturas XPM usando miniLibX
- [ ] Mapear texturas nas paredes corretamente
- [ ] Implementar diferentes texturas para N/S e E/W
- [ ] Calcular coordenadas de textura corretas
- [ ] Otimizar acesso aos dados de textura

---

## 👤 **PESSOA 2 - PARSING & PLAYER SYSTEM**

### 📄 **Sistema de Parsing**
- [ ] Implementar leitor de arquivos .cub
- [ ] Validar formato e extensão dos arquivos
- [ ] Parsear configurações de texturas (NO, SO, WE, EA)
- [ ] Parsear cores de chão e teto (F, C)
- [ ] Validar RGB values (0-255)

### 🗺️ **Validação de Mapas**
- [ ] Parsear grid do mapa (0,1,N,S,E,W)
- [ ] Validar se mapa é fechado por paredes (1)
- [ ] Verificar se existe exatamente um player
- [ ] Detectar posição e orientação inicial do player
- [ ] Implementar tratamento de erros detalhado

### 🕹️ **Sistema do Player**
- [ ] Implementar movimentação WASD
- [ ] Implementar rotação com setas direcionais
- [ ] Sistema de colisão com paredes
- [ ] Suavização de movimentação
- [ ] Controle de velocidade de movimento/rotação

### ⚙️ **Gerenciamento de Eventos**
- [ ] Configurar hooks de teclado (key press/release)
- [ ] Implementar hook de mouse (bonus)
- [ ] Hook de fechamento de janela (ESC, X)
- [ ] Hook de redimensionamento (tratamento)
- [ ] Sistema de loop principal do jogo

### 🧹 **Limpeza e Finalização**
- [ ] Implementar função de cleanup de memória
- [ ] Liberação adequada de texturas
- [ ] Liberação de estruturas de dados
- [ ] Tratamento de vazamentos de memória
- [ ] Testes finais e debugging

---

## 🤝 **TAREFAS COMPARTILHADAS**

### 🧪 **Testes & Debug**
- [ ] Criar mapas de teste variados
- [ ] Testar casos extremos de parsing
- [ ] Verificar vazamentos com Valgrind
- [ ] Teste de performance
- [ ] Code review cruzado

### 📚 **Documentação**
- [ ] Comentar código complexo
- [ ] Atualizar README com instruções
- [ ] Documentar formato de arquivos .cub
- [ ] Criar exemplos de mapas

### 🎁 **Bonus (Opcional)**
- [ ] Minimap em tempo real
- [ ] Sprites/objetos coletáveis
- [ ] Sistema de portas
- [ ] Controle com mouse
- [ ] Múltiplos níveis

---

## 🚀 **Cronograma Sugerido**

| Semana | Pessoa 1 | Pessoa 2 |
|--------|----------|----------|
| 1 | Setup + Estrutura base | Parsing básico |
| 2 | Raycasting core | Validação de mapas |
| 3 | Renderização | Sistema do player |
| 4 | Texturas | Eventos + Cleanup |
| 5 | Otimização + Testes compartilhados |

## 📝 **Critérios de Avaliação**

- ✅ Compilação sem warnings
- ✅ Sem vazamentos de memória
- ✅ Parsing robusto de arquivos .cub
- ✅ Renderização 3D fluida
- ✅ Controles responsivos
- ✅ Tratamento adequado de erros
- ✅ Norm da 42 respeitada

---

**Dica**: Usem branches separadas no Git e façam merge requests para revisar o código um do outro! 🔄