#ifndef HELPER_H   
#define HELPER_H

// --- BIBLIOTECAS DO METAVISION SDK ---
#include <metavision/sdk/stream/camera.h>
#include <metavision/sdk/base/events/event_cd.h>

// --- BIBLIOTECAS PADRÃO ---
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>
#include <iomanip>
#include <sstream>


// --- CONSTANTE ---
const int GRAVACAO_TEMPO_SEC = 5;


// Função para gerar o nome do arquivo baseado no horário atual
inline std::string gerarNomeArquivo() {
    auto agora = std::chrono::system_clock::now();
    auto em_time_t = std::chrono::system_clock::to_time_t(agora);
    std::stringstream ss;
    // Formato: captura_ANO_MES_DIA_HORA_MIN_SEG.raw
    ss << "captura_" << std::put_time(std::localtime(&em_time_t), "%Y-%m-%d_%H:%M:%S") << ".raw";
    return ss.str();
}

#endif // HELPER_H
