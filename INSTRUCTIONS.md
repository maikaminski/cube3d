# Instruções de Compilação e Execução

## Pré-requisitos

1. **libft**: Coloque sua libft na pasta `libft/`
2. **miniLibX**: Baixe e coloque na pasta `minilibx-linux/`

### Instalação da miniLibX (Linux/WSL):

```bash
# Instalar dependências
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# Baixar miniLibX
git clone https://github.com/42Paris/minilibx-linux.git

# Compilar miniLibX
cd minilibx-linux
make
```

## Compilação

```bash
# Compilar o projeto
make

# Limpar arquivos objeto
make clean

# Limpar tudo
make fclean

# Recompilar
make re
```

## Execução

```bash
# Executar com mapa simples
./cub3D maps/simple.cub

# Executar com mapa de exemplo
./cub3D maps/example.cub
```

## Controles

- **W, A, S, D**: Movimentação
- **Setas direcionais**: Rotação da câmera
- **ESC**: Sair do jogo

## Formato do arquivo .cub

```
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm

F 220,100,0
C 225,230,220

111111
100001
100N01
111111
```

- **NO, SO, WE, EA**: Caminhos para texturas das paredes
- **F**: Cor do chão (RGB)
- **C**: Cor do teto (RGB)
- **1**: Parede
- **0**: Espaço vazio
- **N, S, E, W**: Posição e orientação inicial do jogador

## Estrutura de Pastas

```
cube/
├── src/            # Código fonte
├── includes/       # Headers
├── maps/          # Mapas .cub
├── textures/      # Texturas .xpm
├── libft/         # Biblioteca libft
├── minilibx-linux/ # Biblioteca gráfica
└── Makefile       # Arquivo de compilação
```

## Notas Importantes

- As texturas devem estar no formato XPM
- O mapa deve ser fechado por paredes (1)
- Deve existir exatamente um jogador no mapa
- As cores RGB devem estar entre 0-255