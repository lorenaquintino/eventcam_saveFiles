#include "helper.h" // Inclui nosso arquivo de configuração

using namespace std;


int saveEventFile(){
Metavision::Camera camera;
std::string OUTPUT_FILENAME = gerarNomeArquivo();

    try {
        // Conexão
        camera = Metavision::Camera::from_first_available();
    } catch (const std::exception &e) {
        std::cerr << "Erro: O SDK nao encontrou a camera." << std::endl;
        return 1;
    }

    // Iniciar Stream
    camera.start();
    std::cout << ">> Camera LIGADA. Fluxo iniciado..." << std::endl;

    // Pausa para estabilizar o sensor 
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Iniciar Gravação 
    camera.start_recording(OUTPUT_FILENAME);
    std::cout << ">> GRAVANDO dados em: " << OUTPUT_FILENAME << std::endl;

    // Aguardar tempo de gravação
    std::this_thread::sleep_for(std::chrono::seconds(GRAVACAO_TEMPO_SEC));

    // Finalizar 
    std::cout << ">> Encerrando gravacao..." << std::endl;
    
    camera.stop_recording(); // Manda o sinal de parar de escrever
    
    int contador = 0;
    while (camera.is_running() &&  contador < 100) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    contador++;
    } 

    camera.stop(); // Desliga o sensor
    std::cout << ">> Gravacao finalizada com sucesso!" << std::endl;
    std::cout << ">> Camera desligada." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    // para retornar ao menu
    return 0;

}



void mainMenu(){
    char opcao = ' '; // Começa com vazio
    bool rodando = true; // Variável de controle do while

    // O loop WHILE vai rodar enquanto 'rodando' for verdadeiro
    while(rodando == true) {
        
    system("clear");

        cout << "\n-----------------------" << endl;
        cout << " A - Salvar eventos" << endl;
        cout << " B - Sair" << endl;
        cout << "-----------------------" << endl;
        cout << "Digite: ";
        
        cin >> opcao; // Lê o que você digitou no teclado

        switch(opcao) {
            case 'A':
            case 'a':
                saveEventFile();
                break; // Sai do switch e volta pro while

            case 'B':
            case 'b':
                cout << "Saindo..." << endl;
                rodando = false; // Isso fará o while parar na próxima verificação
                break;

            default:
                cout << "Opcao invalida, tente de novo." << endl;
        }
    }
}


int main() {
    
    mainMenu();

    return 0;
}
