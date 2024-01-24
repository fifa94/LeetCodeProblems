import paramiko

# Nastavení připojení
hostname = "192.168.50.208"
username = "filip"
password = "AbsinTh80%"
port = 22

# Vytvoření instance SSHClient
client = paramiko.SSHClient()
client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

try:
    # Připojení k serveru
    client.connect(hostname, port=port, username=username, password=password)

    # Odeslání příkazu na vypnutí serveru s použitím sudo
    command = "echo {} | sudo -S shutdown -h now".format(password)
    stdin, stdout, stderr = client.exec_command(command)

    # Získání výstupu
    output = stdout.read().decode("utf-8")
    error = stderr.read().decode("utf-8")

    # Výpis výstupu a chyb (pokud existují)
    print("Výstup:", output)
    print("Chyby:", error)

finally:
    # Uzavření SSH spojení
    client.close()
