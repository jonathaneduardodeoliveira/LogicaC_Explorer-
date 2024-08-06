#include <stdio.h>
#include <windows.h>
#include <commdlg.h>

void imprimirArquivo(const char *filePath) {
    // Enviar para a impressora padrão
    ShellExecute(NULL, "print", filePath, NULL, NULL, SW_HIDE);
}

int main() {
    char filePath[MAX_PATH] = { 0 };

    // Inicializar a estrutura OPENFILENAME
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFile = filePath;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(filePath);
    ofn.lpstrFilter = "Todos os Arquivos\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrTitle = "Selecione o arquivo para imprimir";
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    // Abrir a caixa de diálogo para selecionar um arquivo
    if (GetOpenFileName(&ofn)) {
        // Imprimir o arquivo selecionado
        imprimirArquivo(filePath);
    }

    return 0;
}
