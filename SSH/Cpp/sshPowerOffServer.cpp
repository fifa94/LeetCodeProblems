#include <libssh/libssh.h>
#include <iostream>
/* g++ sshPowerOffServer.cpp -o sshPowerOffServer -lssh */
int main() {
    // Inicializace knihovny libssh
    ssh_session session = ssh_new();
    if (session == NULL) {
        std::cerr << "Nelze inicializovat libssh." << std::endl;
        return 1;
    }

    // Nastavení parametrů připojení
    const char* hostname = "192.168.50.208";
    const char* username = "filip";
    const char* password = "AbsinTh80%";
    int port = 22;

    // Nastavení parametrů do struktury session
    ssh_options_set(session, SSH_OPTIONS_HOST, hostname);
    ssh_options_set(session, SSH_OPTIONS_USER, username);
    ssh_options_set(session, SSH_OPTIONS_PORT, &port);

    // Připojení k SSH serveru
    int rc = ssh_connect(session);
    if (rc != SSH_OK) {
        std::cerr << "Chyba při připojování k SSH serveru." << std::endl;
        return 1;
    }

    // Autentizace pomocí hesla
    if (ssh_userauth_password(session, NULL, password) != SSH_AUTH_SUCCESS) {
        std::cerr << "Chyba při autentizaci." << std::endl;
        ssh_disconnect(session);
        ssh_free(session);
        return 1;
    }

    // Otevření kanálu pro interakci
    ssh_channel channel = ssh_channel_new(session);
    if (channel == NULL) {
        std::cerr << "Nelze vytvořit SSH kanál." << std::endl;
        ssh_disconnect(session);
        ssh_free(session);
        return 1;
    }

    // Otevření interaktivního kanálu
    if (ssh_channel_open_session(channel) != SSH_OK) {
        std::cerr << "Nelze otevřít SSH session kanál." << std::endl;
        ssh_channel_free(channel);
        ssh_disconnect(session);
        ssh_free(session);
        return 1;
    }

    // Odeslání příkazu na vypnutí serveru (např. pomocí příkazu shutdown)
    if (ssh_channel_request_exec(channel, "sudo shutdown -h now") != SSH_OK) {
        std::cerr << "Chyba při odesílání příkazu na vypnutí serveru." << std::endl;
        ssh_channel_free(channel);
        ssh_disconnect(session);
        ssh_free(session);
        return 1;
    }

    // Uzavření kanálu a odpojení
    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);
    ssh_disconnect(session);
    ssh_free(session);

    std::cout << "Příkaz na vypnutí serveru byl úspěšně odeslán." << std::endl;

    return 0;
}
