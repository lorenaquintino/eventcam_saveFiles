#ifndef HELPER_H   // Mudou de APP_CONFIG_H para HELPER_H
#define HELPER_H

// --- BIBLIOTECAS DO METAVISION SDK ---
#include <metavision/sdk/stream/camera.h>
#include <metavision/sdk/base/events/event_cd.h>

// --- BIBLIOTECAS PADRÃO ---
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

// --- CONSTANTES ---
const std::string OUTPUT_FILENAME = "meu_evento_voris.raw";
const int GRAVACAO_TEMPO_SEC = 5;

#endif // HELPER_H
