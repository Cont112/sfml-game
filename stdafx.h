#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "include/Entidades/Personagens/Jogador.h"
#include "include/Entidades/Personagens/Inimigos/Inimigo.h"
#include "include/Entidades/Personagens/Inimigos/Esqueleto.h"
#include "include/Entidades/Personagens/Inimigos/Mago.h"
#include "include/Entidades/Obstaculos/Obstaculo.h"
#include "include/Entidades/Obstaculos/Plataforma.h"
#include "include/Entidades/Obstaculos/Caixa.h"
#include "include/Gerenciadores/Gerenciador_Grafico.h"
#include "include/Gerenciadores/Gerenciador_Colisoes.h"
#include "include/Gerenciadores/Gerenciador_Eventos.h"
#include "include/Ente.h"
#include "include/Listas/Lista.h"
#include "include/Listas/Lista_Entidades.h"
#include "include/Fases/Fase.h"
#include "include/Fases/Bosque.h"
#include "include/Fases/Castelo.h"
#include "include/Menus/Menu_Principal.h"
#include "include/Menus/Menu_Fases.h"
#include "include/Menus/Menu_Pause.h"
#include "include/Menus/Menu_Jogadores.h"
#include <vector>

#define WIDTH 1280.0f
#define HEIGHT 720.0f