#include <FEHLCD.h>
#include <FEHImages.h>
#include <FEHUtility.h>
#include <FEHKeyboard.h>
#include <FEHRandom.h>
#include <LCDColors.h>
#include <FEHSound.h>
#include <stdio.h>

void WelcomeScreen();
void GameMenu();
void BackButton();
void PlayGame();
void ViewStatistics();
void ViewInstructions();
void ViewCredits();

int main()
{
    LCD.SetBackgroundColor(WHITE);
    LCD.Update();
    LCD.Clear();

    WelcomeScreen();

    while(true)
    {
        GameMenu();

        int x, y;
        if(LCD.Touch(&x, &y))
        {
            // Play Game Button
            if(x >= 90 && x <= 210 && y >= 65 && y <= 95)
            {
                LCD.Clear();
                PlayGame();
                BackButton();
                // Game logic would go here
            }
            // View Statistics Button
            else if(x >= 50 && x <= 230 && y >= 105 && y <= 135)
            {
                LCD.Clear();
                ViewStatistics();
                BackButton();
                // Statistics logic would go here
            }
            // View Instructions Button
            else if(x >= 50 && x <= 230 && y >= 145 && y <= 175)
            {
                LCD.Clear();
                ViewInstructions();
                BackButton();
                // Instructions logic would go here
            }
            // View Credits Button
            else if(x >= 70 && x <= 210 && y >= 185 && y <= 215)
            {
                LCD.Clear();
                ViewCredits();
                BackButton();
                // Credits logic would go here
            }
        }
        Sleep(0.1);
    }
    return 0;
}

void GameMenu()
{
    LCD.SetFontColor(SCARLET);
    LCD.SetFontScale(2.0);
    LCD.WriteAt("Game Menu", 52, 10);
    LCD.DrawHorizontalLine(50, 50, 270);

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Play Game", 106, 70);
    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(98, 62, 124, 34);
    LCD.Update();

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("View Statistics", 70, 110);
    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(62, 102, 196, 34);
    LCD.Update();

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("View Instructions", 58, 150);
    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(50, 142, 220, 34);
    LCD.Update();

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("View Credits", 88, 190);
    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(80, 182, 160, 34);
    LCD.Update();
}

void WelcomeScreen()
{
    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Welcome to", 100, 20);
    LCD.SetFontColor(SCARLET);
    LCD.SetFontScale(2.0);
    LCD.WriteAt("Animal", 90, 80);
    LCD.SetFontColor(SCARLET);
    LCD.SetFontScale(2.0);
    LCD.WriteAt("Memory Match!", 5, 130);
    Sleep(5.0);
    LCD.Clear();
    LCD.Update();
}

void BackButton()
{
    int x, y;
    LCD.SetFontColor(BLUE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("Back to Menu", 10, 10);
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(5, 5, 85, 20);

    while (true)
    {
    if (LCD.Touch(&x, &y))
    {
        if (x >= 5 && x <= 80 && y >= 5 && y <= 25)
        {
        LCD.Clear();
        GameMenu();
        return;
        }
    }
    Sleep(0.1);
    }
    LCD.Update();
}

void PlayGame()
{
    LCD.SetFontColor(SCARLET);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Select Difficulty", 55, 40);
    LCD.DrawLine(50, 65, 280, 65);

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Easy", 138, 100);
    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(90, 90, 140, 36);
    LCD.Update();

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Medium", 125, 150);
    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(90, 140, 140, 36);
    LCD.Update();

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Hard", 138, 200);
    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(90, 190, 140, 36);
    LCD.Update();
}

void ViewStatistics()
{
    LCD.SetFontColor(SCARLET);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Statistics", 108, 40);
    LCD.DrawLine(50, 65, 280, 65);

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Easy Mode", 105, 100);
    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(90, 90, 140, 36);
    LCD.Update();

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Medium Mode", 93, 150);
    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(90, 140, 140, 36);
    LCD.Update();

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Hard Mode", 105, 200);
    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(90, 190, 140, 36);
    LCD.Update();
    // Statistics display logic would go here
}

void ViewInstructions()
{
    LCD.SetFontColor(SCARLET);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Instructions", 88, 40);
    LCD.DrawHorizontalLine(70, 50, 270);

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("How to Play:", 88, 75);
    LCD.Update();

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("Select a difficulty to start the game.", 46, 95);
    LCD.WriteAt("Each level has a set time limit.", 64, 105);
    LCD.WriteAt("Match all pairs of cards before time runs out.", 22, 115);
    LCD.WriteAt("Once matched, the animals will make their sound", 19, 125);
    LCD.WriteAt("and head to the farm!", 97, 135);
    LCD.WriteAt("Unmatched cards will flip back over.", 52, 145);

    LCD.SetFontScale(1.0);
    LCD.WriteAt("How to Win:", 94, 165);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("If you can match all cards", 82, 185);
    LCD.WriteAt("within the time limit,", 94, 195);
    LCD.WriteAt("you win!", 136, 205);

    LCD.Update();
}

void ViewCredits()
{
    LCD.SetFontColor(SCARLET);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Credits", 118, 30);
    LCD.DrawHorizontalLine(50, 80, 240);

    LCD.SetFontColor(GRAY);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Developed by:", 82, 65);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("Carrie Evans", 124, 85);
    LCD.WriteAt("Maria Morales-Cortes", 100, 100);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Graphics by:", 88, 125);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("Carrie Evans", 124, 145);
    LCD.WriteAt("Maria Morales-Cortes", 100, 160);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Sound Effects by:", 58, 185);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("Carrie Evans", 124, 205);
    LCD.WriteAt("Maria Morales-Cortes", 100, 220);
    LCD.Update();
}
