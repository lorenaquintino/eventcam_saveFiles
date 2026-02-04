#include "helper.h" // Inclui nosso arquivo de configuração

using namespace std;

int saveEventFile(){
 Metavision::Camera camera;

    // 1. Conexão
    try {
        camera = Metavision::Camera::from_first_available();
    } catch (const std::exception &e) {
        std::cerr << "Erro: O SDK nao encontrou a camera." << std::endl;
        return 1;
    }

    // 2. Iniciar Stream 
    camera.start();
    std::cout << ">> Camera LIGADA. Fluxo iniciado..." << std::endl;

    // Pausa para estabilizar
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // 3. Iniciar Gravação 
    camera.start_recording(OUTPUT_FILENAME);
    std::cout << ">> GRAVANDO dados em: " << OUTPUT_FILENAME << std::endl;

    // 4. Aguardar tempo de gravação
    std::this_thread::sleep_for(std::chrono::seconds(GRAVACAO_TEMPO_SEC));

    // 5. Finalizar
    camera.stop_recording();
    std::cout << ">> Gravacao finalizada." << std::endl;

    camera.stop();
    std::cout << ">> Camera desligada." << std::endl;


}


void mainMenu(){
    char opcao = ' '; // Começa com vazio
    bool rodando = true; // Variável de controle do while

    // O loop WHILE vai rodar enquanto 'rodando' for verdadeiro
    while(rodando == true) {
        
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
