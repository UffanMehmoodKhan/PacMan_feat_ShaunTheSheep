#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include"movments.h"
#include"brick.h"
#include"displayscreens.h"
#include"Ghosts.h"
#include"RedGhost.h"
#include"PinkGhost.h"
#include"Orangeghost.h"
#include"fstream"


using namespace std;
using namespace sf;
Texture  text;
RectangleShape back; // to display the sides
Texture tt; // to load that image
// Counter ka malsa hai or respwan ka
void humanmovment(int& up, int& left, int& down, int& right, bool& blockageup, bool& blockageleft, bool& blockagedown, bool& blockageright, movments & m1, float dt)
{
    if (up > 0 && blockageup == false)
    {
        m1.velocitypacman.y = -m1.movmentspeedpacman * dt;
    }
    if (down > 0 && blockagedown == false)
    {
        m1.velocitypacman.y = m1.movmentspeedpacman * dt;           // Human movment 
    }
    if (left > 0 && blockageleft == false)
    {
        m1.velocitypacman.x = -m1.movmentspeedpacman * dt;
    }
    if (right > 0 && blockageright == false)
    {
        m1.velocitypacman.x = m1.movmentspeedpacman * dt;
    }
}
bool intersectionchecking(Sprite& pacman, Ghosts * Allghosts[4])
{
    Vector2f pacmanpos, redghostpos, pinkghostpos,orangeghostpos;
    pacmanpos = pacman.getPosition();
    redghostpos = Allghosts[0]->getghostSP().getPosition();
    pinkghostpos = Allghosts[1]->getghostSP().getPosition();
    orangeghostpos= Allghosts[2]->getghostSP().getPosition();
    int xp = ((int)pacmanpos.x - 200) / 50;
    int yp = ((int)pacmanpos.y - 95) / 50;
    int xrg = ((int)redghostpos.x - 200) / 50;
    int yrg = ((int)redghostpos.y - 95) / 50;
    int xpg= ((int)pinkghostpos.x - 200) / 50;
    int ypg = ((int)pinkghostpos.y - 95) / 50;
    int xORG= ((int)orangeghostpos.x - 200) / 50;
    int yORG = ((int)orangeghostpos.y - 95) / 50;
    // do the same for rest of the 3 ghosts as well
    /*cout << xp << "--- " << xrg << endl;
    cout << yp << "--- " << yrg << endl;*/
    if ((xp == xrg && yp == yrg) || (xp == xpg  && yp == ypg) || (xp == xORG && yp == yORG))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int updateHighScore(int newScore) {
    std::ifstream file("highscore.txt"); // Open the file

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return -1; // Return an error value
    }

    int currentHighScore;
    file >> currentHighScore; // Read the current high score from the file
    file.close(); // Close the file

    if (newScore > currentHighScore) {
        std::ofstream file("highscore.txt"); // Open the file for writing

        if (!file.is_open()) {
            std::cerr << "Failed to open the file." << std::endl;
            return -1; // Return an error value
        }

        file << newScore; // Update the high score in the file
        file.close(); // Close the file

        std::cout << "New high score updated!" << std::endl;
        return newScore; // Return the new high score
    }
    else {
        std::cout << "Current high score: " << currentHighScore << std::endl;
        return currentHighScore; // Return the current high score
    }
}

   
    
class gamemaps
{
    Vector2f playerpos;
public:
    Sprite pacman;
    int gridlength;
    brick*** printarr;
    int arr[16][16] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 4, 1, 1, 1, 4, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 4, 0, 0, 1, 4, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };
   
    
    /// 0 shows pellet 
    // 1 shows wall
    // 2 shows blank space
    // 3 shows door
    // 4 shows cherry
    gamemaps(RenderWindow & window, movments& m1, float& dt, Clock dt_clock)
    {
        gridlength = 16;
        playerpos = Vector2f(575.0f, 175.0f);
        printarr = new brick * *[16];
        for (int i = 0; i < 16; i++)
        {
            printarr[i] = new brick * [16];
        }
        setupplayer(); // Intial poition of Player.
        setmapwalls(); // Map Walls and bricks
        print(window, m1, dt, dt_clock);
    }
    void setupplayer()
    {
        text.loadFromFile("zohaib.png");
        text.setSmooth(true);
        pacman.setTexture(text);
        pacman.setPosition(playerpos);
        pacman.setTextureRect(IntRect(0, 0, 40, 40));
        pacman.setOrigin(25.0f, 25.0f);
    }
    void setmapwalls()
    {
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                if (arr[i][j] == 1)
                {
                    printarr[i][j] = new brick("walls.png", j * 50 + 200, i * 50 + 95);
                }
                else if (arr[i][j] == 0)
                {
                    printarr[i][j] = new brick("pellets.png", j * 50 + 200, i * 50 + 95);
                }
                else if (arr[i][j] == 2)
                {
                    printarr[i][j] = new brick("blankspace.png", j * 50 + 200, i * 50 + 95);
                }
                else if (arr[i][j] == 3 && j == 15)
                {
                    printarr[i][j] = new brick("rightdoor.png", j * 50 + 200, i * 50 + 95);
                }
                else if (arr[i][j] == 3 && j == 0)
                {
                    printarr[i][j] = new brick("leftdoor.png", j * 50 + 200, i * 50 + 95);
                }
                else if (arr[i][j] == 4)
                {
                    printarr[i][j] = new brick("cherry.png", j * 50 + 200, i * 50 + 95);
                }

            }

        }
    }
    void print(RenderWindow & window, movments m1, float dt, Clock dt_clock)
    {

        
      /*  sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }*/

        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                window.draw(printarr[i][j]->getsprite()); // Prints All the respective tiles in print arr
            }
        }
    }
    void collisionchecking(movments& m1,int& up,int& left,int& down,int& right,bool& blokeageup,bool& blocakageleft,bool& blocakgedown, bool& blackageright)
    {/*Music eatingsound;
    eatingsound.openFromFile("pacman_chomp.wav");*/
        Vector2f currentpos = pacman.getPosition();
        if (up == 1)
        {
            int x = ((int)currentpos.x - 200) / 50;
            int y = ((int)currentpos.y + 25 - 95) / 50;
            // is doing sperately because of differnce in origin 
            if (arr[y - 1][x] == 1) // looking a step ahead to see what it is 
            {
                up = 0;
                blokeageup = true;
            }
        }
        else if (left == 1)
        {
            int x = ((int)currentpos.x + 25 - 200) / 50;
            int y = ((int)currentpos.y - 95) / 50;
            // is doing sperately because of differnce in origin 
            if (arr[y][x - 1] == 1) // looking a step ahead to see what it is 
            {
                left = 0;
                blocakageleft = true;
            }

        }
        else if (down == 1)
        {
            int x = ((int)currentpos.x - 200) / 50;
            int y = ((int)currentpos.y - 25 - 95) / 50;
            // is doing sperately because of differnce in origin 
            if (arr[y + 1][x] == 1) // looking a step ahead to see what it is 
            {
                down = 0;
                blocakgedown = true;
            }


        }
        else if (right == 1)
        {
            int x = ((int)currentpos.x - 25 - 200) / 50;
            int y = ((int)currentpos.y - 95) / 50;
            // is doing sperately because of differnce in origin 
            if (arr[y][x + 1] == 1) // looking a step ahead to see what it is 
            {
                right = 0;
                blackageright = true;
            }
        }
    }
    void printingreplacments(int & score,int & counter,displayscreens & allscreens,RenderWindow & window,bool pacmaneatornot,Sound & arneamusic)
    {
        static int x = 0,y=0;
        static float previoustime = 0;
        if (pacmaneatornot)
        {
            pacman.setPosition(Vector2f(575.0f, 175.0f));
        }
        else
        {
            Vector2f currentpos = pacman.getPosition();
            x = ((int)currentpos.x - 200) / 50;
            y = ((int)currentpos.y - 95) / 50;
            if ((y < 15 && y>0 && x < 15 && x>0 ) || ((arr[y][x] == 3 && x == 0)|| arr[y][x] == 3 && x == 15))   // So it does not go and try to write when pacman Is gone during system pause
            {
                if (arr[y][x] == 0)
                {
                    allscreens.score10display(window);
                    /*eatingsound.play();*/

                    printarr[y][x] = new brick("blankspace.png", (x * 50) + 200, (y * 50) + 95); // makes edit is printing array
                    // checking if player is standing on indices taht either conatins pellets or cherry and then remove it 
                    arr[y][x] = 2;
                    score += 10;
                    counter++;
                    arneamusic.play();
                }
                if (arr[y][x] == 4)
                {
                    /*eatingsound.play();*/
                    printarr[y][x] = new brick("blankspace.png", (x * 50) + 200, (y * 50) + 95); // makes edit inn printing array
                    // checking if player is standing on indices taht either conatins pellets or cherry and then remove it 
                    arr[y][x] = 2;
                }
                if (arr[y][x] == 3 && x == 0)
                {
                    pacman.setPosition(200.0f + 750.0f, 520.0f);
                    // left door and setting cords of right gate next tile
                }
                if (arr[y][x] == 3 && x == 15)
                {
                    pacman.setPosition(250.0f, 520.0f);
                    // right door and setting cords of left gate            
                }
            }
            else
            {
                pacman.setPosition(Vector2f(575.0f, 175.0f)); 
            }
        }
    }
    void cherryeating(movments& m1, float& timeelapsed,Ghosts* allghosts[4],bool & pacmaneatornot , int & score,RenderWindow & window,Sound & scaredghost, Sound & eatingcherry,Sound & eatghost)
    {
        static float previoustime = 0;
        static int c = 0;
        Vector2f currentpos = pacman.getPosition();
        int x = ((int)currentpos.x - 200) / 50;
        int y = ((int)currentpos.y - 95) / 50;
        if (arr[y][x] == 4)
        {
            bool flag = false;
            //m1.movmentspeedredghost = 40.0f;
            previoustime = timeelapsed;
            allghosts[0]->colourandspeed(m1);
            allghosts[1]->colourandspeed(m1);
            allghosts[2]->colourandspeed(m1);
            eatingcherry.play();
            scaredghost.play();
            //arenamusic.stop();
            // redghost colour change
        }
        if (timeelapsed > previoustime + 3.0) //  After 3 sec are over of eating cherry 
        {
            scaredghost.stop();
         
            allghosts[0]->revert(m1);  // Is returninng ghost to its normal speed and colour
            allghosts[1]->revert(m1);
            allghosts[2]->revert(m1);

            c = 0;
            if (intersectionchecking(pacman,allghosts))
            {
                pacmaneatornot = true;

                // life deduction and reset every thing apart from score and lifes
            }
        }
        else if (intersectionchecking(pacman, allghosts))
        {
            
            if (c==0) // So that score of 200 Only gets add once 
            {
                score += 200;
                c++;
                allghosts[0]->respawn();
                allghosts[1]->respawn();
                allghosts[2]->respawn();
                eatghost.play();
                // revert the ghost to its orignal place
            }
            // display 200 +
            // respawn and add in the score
        }

    }
    void setupplayeradvanced(int zohaibornot)
    {
        if (zohaibornot==1)
        {
            text.loadFromFile("zohaib.png");
            pacman.setTexture(text);
        }
        else if (zohaibornot==2)
        {
            text.loadFromFile("uffan.png");
            pacman.setTexture(text);
        }
        else if (zohaibornot==3)
        {
            text.loadFromFile("sheep.png");
            pacman.setTexture(text);
        }
    }
};
void keyboarddetector(int& up, int& left, int& down, int& right, bool& blockageup, bool& blockageleft, bool& blockagedown, bool& blockageright,gamemaps & map1,bool pacmaneatornot)
{
    if (pacmaneatornot)
    {

    }
    else
    {
        Vector2f playerpos;
        playerpos = map1.pacman.getPosition();
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            up = 1;
            left = 0, right = 0, down = 0;
            blockageleft = false; blockagedown = false; blockageright = false;
            playerpos.x /= 50.0f;
            int x = playerpos.x;
            // to keep the sprite on track
            map1.pacman.move(2.0f, 0.0f);
            map1.pacman.setPosition((x * 50) + 20.0f, playerpos.y);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            left = 1;
            up = 0, right = 0, down = 0;
            blockageup = false; blockagedown = false; blockageright = false;
            playerpos.y /= 50.0f;
            int x = playerpos.y;                                      // to keep the sprite on track 

            map1.pacman.move(0.0f, 2.0f);
            map1.pacman.setPosition(playerpos.x, (x * 50) + 20.0f);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            down = 1;
            left = 0, right = 0, up = 0;
            blockageleft = false; blockageup = false; blockageright = false;
            playerpos.x /= 50.0f;
            int x = playerpos.x;                                       // to keep the sprite on track 

            map1.pacman.move(2.0f, 0.0f);
            map1.pacman.setPosition((x * 50) + 25.0f, playerpos.y);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            right = 1;
            left = 0, up = 0, down = 0;
            blockageleft = false; blockagedown = false; blockageup = false;
            playerpos.y /= 50.0f;
            int x = playerpos.y;                                       // to keep the sprite on track 

            map1.pacman.move(0.0f, 2.0f);
            map1.pacman.setPosition(playerpos.x, (x * 50) + 25.0f);

        }
    }
}

int main()
{
    int totallifes = 3, score = 0, left = 0, up = 0, right = 0, down = 0, counter = 0, menuchoice = 0;
    Ghosts* Allghosts[4];
    Allghosts[0] = new RedGhost;
    Allghosts[1] = new PinkGhost;
    Allghosts[2] = new Orangeghost;
    bool blockageup = false, blockageleft = false, blockagedown = false, blockageright = false, gameendornot = false;  // keep on moving
   // so that user cannot update the value of up to 1 again after it has been stop by clicking up key again
    Clock dt_clock;
    float dt = 0; // Time Between intervals
    float timeelapsed = 0; // Total Time passed since the beggining
    int zohaibornot = 0 ,highscore=0;
    sf::RenderWindow window(sf::VideoMode(1200, 1100), "My window");
    movments m1;
    displayscreens allscreens;
    gamemaps Map1(window, m1, dt, dt_clock); // When the constructor get called it prints the gamme once.
    /*back.setSize(Vector2f(1200.0f, 1100.0f));
    tt.loadFromFile("gameBG.png");
    back.setTexture(&tt);
    window.draw(back);*/
    Sound intromusic,arenamusic,eatingmusic,scaredghost,eatingcherry,eatghost;
    SoundBuffer introbuffer,arenabuffer,eatingbuffer,scaredghostbuffer,eatingcherrybuffer,eatghostbuffer;
    introbuffer.loadFromFile("intromusic.wav");
    intromusic.setBuffer(introbuffer);
    intromusic.setVolume(50);
    arenabuffer.loadFromFile("pacman_chomp.wav");
    arenamusic.setBuffer(arenabuffer);
    arenamusic.setVolume(10);
    eatingbuffer.loadFromFile("pacman_death.wav");
    eatingmusic.setBuffer(eatingbuffer);
    scaredghostbuffer.loadFromFile("pacman_intermission.wav");
    scaredghost.setBuffer(scaredghostbuffer);
    scaredghost.setVolume(30);
    eatingcherrybuffer.loadFromFile("pacman_eatfruit.wav");
    eatingcherry.setBuffer(eatingcherrybuffer);
    eatghostbuffer.loadFromFile("pacman_eatghost.wav");
    eatghost.setBuffer(eatghostbuffer);
    while (window.isOpen())
    {
        window.setFramerateLimit(90);
       
        window.clear();

        static int music = 0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Impliment Menu and choice to display differnet screens
        // main menu screen
       
        if (menuchoice == 0)
        {
            if (music == 0)
            {
                intromusic.play();
                intromusic.setLoop(true);
                /*arenamusic.stop();
                arenamusic.setLoop(false);*/
                music++;
            }
            allscreens.mainmenu(menuchoice, window, event, Allghosts, totallifes,music);
            Map1.pacman.setPosition(575.0f, 175.0f);// so that when menu screen is fiished game is reset
           // intromusic.setLoop(true);
        }
        //Gamescreen and mechannic
        if (menuchoice == 1)
        {
            if (music == 0)
            {
                /*arenamusic.play();
                arenamusic.setLoop(true);*/
                music++;
                intromusic.stop();
                intromusic.setLoop(false);
            }
            bool pacmaneatornot = false;
            Clock Te_clock;
            //window.clear(Color::Black);
            RectangleShape back; // to display the sides
            Texture tt; // to load that image

            Vector2f currentpos = Map1.pacman.getPosition();
            int x = ((int)currentpos.x - 200) / 50;
            int y = ((int)currentpos.y - 95) / 50;
            if (Map1.arr[y][x] == 0)
            {
                allscreens.score10display(window);
            }
            m1.velocitypacman.x = 0.0f; // pacman
            m1.velocitypacman.y = 0.0f;
            m1.velocityredghost.x = 0.0f; // red ghost
            m1.velocityredghost.y = 0.0f;
            m1.velocitypinkghost.x = 0.0f; // pink ghost 
            m1.velocitypinkghost.y = 0.0f;
            m1.velocityorangeghost.x = 0.0f; // orange ghost 
            m1.velocityorangeghost.y = 0.0f;
            //// so that it does not go diagonally
            // time elapsed * movment speed = velocity in pixels and thats how much our sprite move
            dt = dt_clock.restart().asSeconds();// is the time in b/w every interval
            timeelapsed += dt; // Adding that time
            keyboarddetector(up, left, down, right, blockageup, blockageleft, blockagedown, blockageright, Map1, pacmaneatornot);// Detects which key has been pressed
            humanmovment(up, left, down, right, blockageup, blockageleft, blockagedown, blockageright, m1, dt);// Function name
            Map1.print(window, m1, dt, dt_clock);// Draw every thing after this otherwise will be burried underneath the bricks
            Map1.cherryeating(m1, timeelapsed, Allghosts, pacmaneatornot, score, window,scaredghost,eatingcherry,eatghost);// will  decrease the speed of ghosts
            // Will Add in score 
            Map1.printingreplacments(score, counter, allscreens, window, pacmaneatornot,arenamusic); // Will replace the bricks // will laso update the intger array
            // This sequence of Cherry eating and then printing replacments need to be followed
            highscore=updateHighScore(score);

            if (counter < 2)
            {
                Map1.setmapwalls();
                Allghosts[0]->respawn();
                Allghosts[1]->respawn();
                Allghosts[2]->respawn();
            }
            Allghosts[0]->target(window, m1, Map1.pacman, dt, Map1.arr, left, right, down, up);
            Allghosts[1]->target(window, m1, Map1.pacman, dt, Map1.arr, left, right, down, up);
            Allghosts[2]->target(window, m1, Map1.pacman, dt, Map1.arr, left, right, down, up);
            // ".MOVE" of red ghost move function // is also implimented inside it 
            Map1.pacman.move(m1.velocitypacman);
            allscreens.gamescreen(window, event, menuchoice,music,Allghosts,Map1.arr,counter,score,totallifes);// Things Printed on the side and below
            window.draw(Map1.pacman);
            window.draw((Allghosts[0]->getghostSP())); // Drawing the Red ghost
            window.draw((Allghosts[1]->getghostSP())); // Drawing the pink ghost
            window.draw((Allghosts[2]->getghostSP())); // Drawing the Orange ghost
            //window.draw((Allghosts[3]->getghostSP()));
            allscreens.scoresandlife(window, score, totallifes,highscore);
            Map1.collisionchecking(m1, up, left, down, right, blockageup, blockageleft, blockagedown, blockageright); // Walls detetction  
            if (pacmaneatornot) // pacman have been eaten once
            {
                pacmaneatornot = false;
                totallifes--;
                //   Map1.pacman.setPosition(575.0f, 175.0f);
                //   eaten once message displayed;

                window.clear();
                allscreens.pacmaneaten(window);
                window.display();
                arenamusic.stop();
                eatingmusic.play();
                sleep(milliseconds(1500));
                arenamusic.play();
                Allghosts[0]->respawn(); // back to cell after killing pacman
                Allghosts[1]->respawn();
                Allghosts[2]->respawn();
                //  Allghosts[3]->respawn();
                // life deduction and reset every thing apart from score and lifes
            }
            if (totallifes == 0)
            {
                // Game ended and you lost los screen display
                menuchoice = 5;

            }
            if (counter == 131)
            {
                menuchoice = 6;
                // you won and display that screen
                
            }
        }
        if (menuchoice == 2)
        {
            // Credits
            allscreens.creditsscreen(window, menuchoice, event);
        }
        if (menuchoice == 3)
        {
            allscreens.choeseyourcharacter(window, menuchoice, event, zohaibornot);
            Map1.setupplayeradvanced(zohaibornot);
        }
        if (menuchoice == 4)
        {
            // impliment loading screen wafter which you will call main menu

            allscreens.loadingscreen(window, menuchoice);
        }
        if (menuchoice == 5)
        {
            allscreens.losingscreen(window, event, menuchoice,music,Map1.arr,counter,score,totallifes);
        }
        if (menuchoice == 6)
        {
            allscreens.winningcreen(window, event, menuchoice, music ,Map1.arr, counter,score, totallifes);
        }
        window.display();
    }
    cout << " Life ended";
}