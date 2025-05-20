#include <stdio.h>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <Cutremur.h>

#define WIDTH 1200
#define HEIGHT 800

bool ShowCustomMessageBox(Rectangle bounds, const char *title, const char *message, int *result)
{
    bool done = false;

    GuiPanel(bounds, title);

    DrawText(message, bounds.x + 20, bounds.y + 40, 18, DARKBLUE);

    if (GuiButton((Rectangle){ bounds.x + bounds.width/2 - 40, bounds.y + bounds.height - 25, 100, 50 }, "INCHIDE")) {
        *result = 1;
        done = true;
    }

    return done;
}

int main()
{
    InitWindow(WIDTH, HEIGHT, "Program de determinare a ratei de cutremur");
    SetTargetFPS(60);
    char aniDeAnaliza[50] = "an-an";

    char startStr[5] = "aa";
    char endStr[5] = "aa";
    int anDeStart = 0;
    int anDeStop = 0;

    bool showFileUpDiag = false;

    bool actiuneCalculPredicti = false;
    bool actiuneAfisareaDatelor = false;

    bool showBox = false;
    int result = 0;

    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, ColorToInt(DARKBLUE));
    GuiSetStyle(BUTTON, TEXT_COLOR_FOCUSED, ColorToInt(BLACK));
    GuiSetStyle(BUTTON, TEXT_COLOR_PRESSED, ColorToInt(GREEN));

    while (!WindowShouldClose())
    {
        //Cat timp fereastra este deschisa se scrie
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        if (GuiButton((Rectangle){ 0, 0, 160, 30 }, "#191#INFO")) {
            showBox = true;
        }

        if (showBox) {
            Rectangle boxBounds = { 20, 450, 500, 300 };
            bool closed = ShowCustomMessageBox(boxBounds,
                                               "#191#Despre Program",
                                               "Creat de: \nCraciun Silviu-Mihai\nPencescu Vlad - Theodor\nPetre Ioan-Iulian\nOprea Mihnea\nVasile Milete-Justin\n\n\nLink catre data provider: https://www.infp.ro",
                                               &result);
            if (closed) showBox = false;
        }


        DrawText("Interfata de analiza si procesare date",WIDTH / 2 - 325,50,35,BLACK);

        //A fi mentionat "goto" in standardele moderne de programare este considerat unsfae code deci cine are chef sa modifice
        if (GuiButton((Rectangle){WIDTH - 200,HEIGHT - 75,200,75}, "#113# Close Window")) goto CLO;

        DrawText("Perioada de analiza si procesare date",25,200,20, BLACK);

        if (GuiButton((Rectangle){20,250,275,50},"#5#Selectare date")) showFileUpDiag = true;

        if (showFileUpDiag) {
            int rezultat = GuiTextInputBox((Rectangle){ WIDTH / 2 - 235,400,500,150},"#5#Selectare ani de analiza","Selectare Ani (an-an)","#5#Selecteaza",aniDeAnaliza,512,NULL);

            if (rezultat == 1) {
                //Debug
                //printf(aniDeAnaliza);
                // Copy first 4 characters for start year
                for (int i = 0; i < 4; i++) {
                    startStr[i] = aniDeAnaliza[i];
                }
                startStr[4] = '\0';

                // Copy next 4 characters after the dash for end year
                for (int i = 0; i < 4; i++) {
                    endStr[i] = aniDeAnaliza[i + 5];
                }
                endStr[4] = '\0';

                // Convert to integers
                anDeStart = atoi(startStr);
                anDeStop = atoi(endStr);

                //printf("an de strat:%d\n",anDeStart);
                //printf("an de stop:%d\n",anDeStop);
            }

            if (rezultat >= 0) showFileUpDiag = false;
        }

        if (GuiButton((Rectangle){WIDTH / 2 - 120,250,275,50}, "#112#Calcularea datelor")) actiuneCalculPredicti = true;

        if (actiuneCalculPredicti) {

           /* //Observatie Se utilizeaza adresa absoluta pentru usurinta si evitarea problemelor eventuale cu executarea exe
            system("Predictie_Cutremure.exe");*/

            cutremure();

            actiuneCalculPredicti = false;
        }

        if (GuiButton((Rectangle){WIDTH - 295,250,275,50},"#123#Afisarea Datelor")) actiuneAfisareaDatelor = true;

        if (actiuneAfisareaDatelor) {

            //system("cd ..&& Predictie_Cutremure.exe");
            system("python main.py");

            actiuneAfisareaDatelor = false;
        }

        EndDrawing();
    }

    CLO:CloseWindow();
    return 0;
}