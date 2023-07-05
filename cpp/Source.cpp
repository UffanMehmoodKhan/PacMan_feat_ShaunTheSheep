//#include<SFML/Graphics.hpp>
//#include <iostream>
//#include <SFML/System.hpp>
//#include<fstream>
//using namespace std;
//using namespace sf;
//
//void drawoutline(RenderWindow& window, int i, int  j)
//{
//    sf::RectangleShape rect(sf::Vector2f(100.f, 100.f));
//    rect.setPosition(sf::Vector2f(j * 100.f, i * 100.f));
//    rect.setFillColor(sf::Color::Transparent);
//    rect.setOutlineThickness(-8.f);
//    rect.setOutlineColor(sf::Color::Yellow);
//    window.draw(rect);
//}
//void chesshistory(int chess[][8])
//{
//
//
//}
//
//class peices
//{
//    
//public:
//    peices() {}
//    virtual ~peices(){}
//    virtual void Initialprint(RenderWindow & window,int a,int b,int ** chess) = 0;
//    virtual bool validationcheck(int fi, int fj, int si, int sj, int** chess) = 0;
//    virtual void futureprint(RenderWindow& window, int i, int j, int** chess) = 0;
//
//};
//class Pawn : public peices
//{
//public:
//    Pawn() : peices()
//    {
//    
//    }
//    ~Pawn()
//    {
//        
//    }
//    bool validationcheck(int fi, int fj, int si, int sj, int** chess)
//    {
//        if (chess[fi][fj] < 0 && fi >= 0 && fi < 8 && si >= 0 && si < 8 && fj >= 0 && fj < 8 && sj >= 0 && sj < 8)
//        {
//            if (fi == 6)
//            {
//                if ((fi - si == 2 ) && (si < fi && sj == fj)&&(chess[fi-2][fj]==0))
//                {
//                    return true;
//                }
//                if (fi - si == 1 && (si < fi && sj == fj) && chess[fi - 1][fj] == 0) return true;
//            }
//            if (fi != 6)
//            {
//                if ((fi - si == 1) && (si < fi && sj == fj) && chess[fi - 1][fj] == 0)
//                {
//                    return true;
//                }
//            }
//            if (chess[fi - 1][fj - 1] > 0 && si == fi - 1 && sj == fj - 1)
//            {
//                return true;
//            }
//            if (chess[fi - 1][fj + 1] > 0 && si == fi - 1 && sj == fj + 1)
//            {
//                return true;
//            }
//        }
//        else if (chess[fi][fj] > 0 && fi >= 0 && fi < 8 && si >= 0 && si < 8 && fj >= 0 && fj < 8 && sj >= 0 && sj < 8)
//        {
//            if (fi == 1)
//            {
//                if ((si - fi == 2) && (fi < si && sj == fj) &&  chess[fi + 2][fj] == 0)
//                {
//                    return true;
//                }
//                if(si - fi == 1 && (fi < si&& sj == fj) && (chess[fi + 1][fj] == 0)) return true;
//            }
//            if (fi != 1)
//            {
//                if ((si - fi == 1) && (fi < si && sj == fj)&& chess[fi + 1][fj] == 0)
//                {
//                    return true;
//                }
//            }
//            if (chess[fi + 1][fj - 1] < 0 && si == fi + 1 && sj == fj - 1)
//            {
//                return true;
//            }
//            if (chess[fi + 1][fj + 1] < 0 && si == fi + 1 && sj == fj + 1)
//            {
//                return true;
//            }
//        }
//        return false;
//
//
//    }
//    void futureprint(RenderWindow& window, int i, int j, int** chess)
//    {
//        int ni = i, nj = j;
//        if (chess[i][j] > 0 && (ni >= 0 && ni < 8 && nj >= 0 && nj < 8))
//            if (i == 1)
//            {
//                if ((ni >= 0 && ni + 1 < 8 && nj >= 0 && nj < 8))
//                    if (chess[ni + 1][nj] == 0)
//                        drawoutline(window, ni + 1, nj);
//                if ((ni >= 0 && ni + 2 < 8 && nj >= 0 && nj < 8))
//                    if (chess[ni + 2][nj] == 0)
//                        drawoutline(window, ni + 2, nj);
//                if ((ni >= 0 && ni + 1 < 8 && nj >= 0 && nj + 1 < 8))
//                    if (chess[ni + 1][nj + 1] < 0)
//                        drawoutline(window, ni + 1, nj + 1);
//                if ((ni >= 0 && ni + 1 < 8 && nj >= 0 && nj - 1 >= 0))
//                    if (chess[ni + 1][nj - 1] < 0)
//                        drawoutline(window, ni + 1, nj - 1);
//            }
//            else
//            {
//                if ((ni >= 0 && ni + 1 < 8 && nj >= 0 && nj < 8))
//                    if (chess[ni + 1][nj] == 0)  drawoutline(window, ni + 1, nj);
//
//                if ((ni >= 0 && ni + 1 < 8 && nj >= 0 && nj + 1 < 8))
//                    if (chess[ni + 1][nj + 1] < 0)
//                        drawoutline(window, ni + 1, nj + 1);
//                if ((ni >= 0 && ni + 1 < 8 && nj >= 0 && nj - 1 >= 0))
//                    if (chess[ni + 1][nj - 1] < 0)
//                        drawoutline(window, ni + 1, nj - 1);
//            }
//
//
//        if (chess[i][j] < 0 && (ni >= 0 && ni < 8 && nj >= 0 && nj < 8))
//            if (i == 6)
//            {
//                if ((ni - 1 >= 0 && ni < 8 && nj >= 0 && nj < 8))
//                    if (chess[ni - 1][nj] == 0)
//                        drawoutline(window, ni - 1, nj);
//                if ((ni - 2 >= 0 && ni < 8 && nj >= 0 && nj < 8))
//                    if (chess[ni - 2][nj] == 0)
//                        drawoutline(window, ni - 2, nj);
//                if ((ni - 1 >= 0 && ni < 8 && nj >= 0 && nj + 1 < 8))
//                    if (chess[ni - 1][nj + 1] > 0)
//                        drawoutline(window, ni - 1, nj + 1);
//                if ((ni - 1 >= 0 && ni < 8 && nj >= 0 && nj - 1 >= 0))
//                    if (chess[ni - 1][nj - 1] > 0)
//                        drawoutline(window, ni - 1, nj - 1);
//            }
//            else
//            {
//                if ((ni - 1 >= 0 && ni < 8 && nj >= 0 && nj < 8))
//                    if (chess[ni - 1][nj] == 0)  drawoutline(window, ni - 1, nj);
//                if ((ni - 1 >= 0 && ni < 8 && nj >= 0 && nj + 1 < 8))
//                    if (chess[ni - 1][nj + 1] > 0)
//                        drawoutline(window, ni - 1, nj + 1);
//                if ((ni - 1 >= 0 && ni < 8 && nj >= 0 && nj - 1 >= 0))
//                    if (chess[ni - 1][nj - 1] > 0)
//                        drawoutline(window, ni - 1, nj - 1);
//            }
//
//
//
//
//    }
//  void Initialprint(RenderWindow& window, int i,int j,int ** chess) override
//    {
//      if (chess[i][j]<0)
//      {
//          IPW(window,i,j);
//      }
//      else
//      {
//          IPB(window,i,j);
//      }
//    }
//  void IPW(RenderWindow & window, int i, int j)
//  {
//      Texture texture;
//      Sprite sprite;
//      texture.loadFromFile("pawn w.png");
//      sprite.setTexture(texture);
//      sprite.setPosition(j * 102, i * 100);
//      window.draw(sprite);
//  }
//  void IPB(RenderWindow& window, int i, int j)
//  {
//      Texture texture;
//      Sprite sprite;
//      texture.loadFromFile("pawn b.png");
//      sprite.setTexture(texture);
//      sprite.setPosition(j * 102, i * 100);
//      window.draw(sprite);
//
//  }
//
//};
//class knight : public peices
//{
//public:
//    knight() : peices()
//    {
//
//    }
//    ~knight()
//    {
//
//    }
//    bool validationcheck(int fi, int fj, int si, int sj, int** chess)
//    {
//        bool possible = false;
//        if (si >= 0 && si < 8 && sj >= 0 && sj < 8)
//            if ((chess[fi][fj] < 0 && chess[si][sj] >= 0) || (chess[fi][fj] > 0 && chess[si][sj] <= 0))//white kight
//            {// if white           &   black             or    black           &  white               &          within boundary      
//                if ((si == fi + 2 || si == fi - 2) && (sj == fj + 1 || sj == fj - 1))      possible = true;
//                else if ((sj == fj + 2 || sj == fj - 2) && (si == fi + 1 || si == fi - 1)) possible = true;
//            }
//        return possible;
//    }
//    void futureprint(RenderWindow& window, int i, int j, int** chess)
//    {
//        if (validationcheck(i, j, i + 2, j + 1, chess) && i + 2 < 8 && j + 1 < 8) drawoutline(window, i + 2, j + 1);
//        if (validationcheck(i, j, i - 2, j + 1, chess) && i - 2 >= 0 && j + 1 < 8) drawoutline(window, i - 2, j + 1);
//        if (validationcheck(i, j, i + 2, j - 1, chess) && i + 2 < 8 && j - 1 >= 0) drawoutline(window, i + 2, j - 1);
//        if (validationcheck(i, j, i - 2, j - 1, chess) && i - 2 >= 0 && j - 1 >= 0) drawoutline(window, i - 2, j - 1);
//
//        if (validationcheck(i, j, i + 1, j + 2, chess) && i + 1 < 8 && j + 2 < 8) drawoutline(window, i + 1, j + 2);
//        if (validationcheck(i, j, i + 1, j - 2, chess) && i + 1 < 8 && j - 2 >= 0) drawoutline(window, i + 1, j - 2);
//        if (validationcheck(i, j, i - 1, j + 2, chess) && i - 1 >= 0 && j + 2 < 8) drawoutline(window, i - 1, j + 2);
//        if (validationcheck(i, j, i - 1, j - 2, chess) && i - 1 >= 0 && j - 2 >= 0) drawoutline(window, i - 1, j - 2);
//    }
//    void Initialprint(RenderWindow& window, int i, int j, int** chess) override
//    {
//        if (chess[i][j] < 0)
//        {
//            IPW(window, i, j);
//        }
//        else
//        {
//            IPB(window, i, j);
//        }
//    }
//    void IPW(RenderWindow& window, int i, int j)
//    {
//        Texture texture;
//        Sprite sprite;
//        texture.loadFromFile("knight w.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 100, i * 100);
//        window.draw(sprite);
//
//    }
//    void IPB(RenderWindow& window, int i, int j)
//    {
//        Texture texture;
//        Sprite sprite;
//        texture.loadFromFile("knight b.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 100, i * 100);
//        window.draw(sprite);
//
//    }
//
//};
//class bishup : public peices
//{
//public:
//    bishup() : peices()
//    {
//
//    }
//    ~bishup()
//    {
//
//    }
//    bool validationcheck(int fi, int fj, int si, int sj, int** chess)
//    {
//        int ffi = fi, ffj = fj, ssi = si, ssj = sj;
//        bool flag = true;
//        if ((chess[fi][fj] < 0 && chess[si][sj] < 0) || (chess[fi][fj] > 0 && chess[si][sj] > 0)) return false;
//        //  white              &  white
//        if (fi >= 0 && fi < 8 && si >= 0 && si < 8 && fj >= 0 && fj < 8 && sj >= 0 && sj < 8)
//        {
//            if (chess[si][sj] == 9) return false; // if it try to kill king 
//            if (si == fi || sj == fj) return false;
//
//            if (si - fi < 0 && sj - fj>0)// upside right
//            {
//                flag = false;
//                while ((ffi >= 0 && ffi < 8 && ssi >= 0 && ssi < 8 && ffj >= 0 && ffj < 8 && ssj >= 0 && ssj < 8))
//                {
//                    if (ffi == ssi && ffj == ssj)
//                    {
//                        flag = true;
//                        break;
//                    }
//                    ffi--;
//                    ffj++;
//                }
//                if (!flag)
//                    return false;
//                ffi = fi - 1, ffj = fj + 1, ssi = si, ssj = sj;
//                while (ffi != ssi || ffj != ssj)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                    if (ffi < ssi && ffj >ssj) break;
//                    ffi--;
//                    ffj++;
//                }
//            }
//
//            ffi = fi, ffj = fj, ssi = si, ssj = sj;
//            if (si - fi < 0 && sj - fj < 0)// upside left
//            {
//                flag = false;
//                while ((ffi >= 0 && ffi < 8 && ssi >= 0 && ssi < 8 && ffj >= 0 && ffj < 8 && ssj >= 0 && ssj < 8))
//                {
//                    if (ffi == ssi && ffj == ssj)
//                    {
//                        flag = true;
//                        break;
//                    }
//                    ffi--;
//                    ffj--;
//                }
//                if (!flag)
//                    return false;
//                ffi = fi - 1, ffj = fj - 1, ssi = si, ssj = sj;
//
//                while (ffi > ssi && ffj > ssj)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                    if (ffi < ssi && ffj < ssj) break;
//                    ffi--;
//                    ffj--;
//                }
//
//            }
//            ffi = fi, ffj = fj, ssi = si, ssj = sj;
//            if (si - fi > 0 && sj - fj > 0)//down right
//            {
//                flag = false;
//                while ((ffi >= 0 && ffi < 8 && ssi >= 0 && ssi < 8 && ffj >= 0 && ffj < 8 && ssj >= 0 && ssj < 8))
//                {
//                    if (ffi == ssi && ffj == ssj)
//                    {
//                        flag = true;
//                        break;
//                    }
//                    ffi++;
//                    ffj++;
//                }
//                if (!flag)
//                    return false;
//                ffi = fi + 1, ffj = 1 + fj, ssi = si, ssj = sj;
//
//                while (ffi < ssi && ffj < ssj)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                    if (ffi > ssi && ffj > ssj) break;
//                    ffi++;
//                    ffj++;
//                }
//            }
//            ffi = fi, ffj = fj, ssi = si, ssj = sj;
//            if (si - fi > 0 && sj - fj < 0)//down left
//            {
//                flag = false;
//                while ((ffi >= 0 && ffi < 8 && ssi >= 0 && ssi < 8 && ffj >= 0 && ffj < 8 && ssj >= 0 && ssj < 8))
//                {
//                    if (ffi == ssi && ffj == ssj)
//                    {
//                        flag = true;
//                        break;
//                    }
//                    ffi++;
//                    ffj--;
//                }
//                if (!flag)
//                    return false;
//                ffi = fi + 1, ffj = fj - 1, ssi = si, ssj = sj;
//
//                while (ffi < ssi && ffj > ssj)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                    if (ffi > ssi && ffj < ssj) break;
//                    ffi++;
//                    ffj--;
//                }
//
//            }
//            return true;
//        }
//        return flag;
//    }
//    void futureprint(RenderWindow& window, int i, int j, int** chess)
//    {
//        int ni = i - 1, nj = j - 1;
//        if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
//        {
//            while (chess[ni][nj] == 0)
//            {
//                drawoutline(window, ni, nj);
//                ni--;
//                nj--;
//                if (!(ni >= 0 && ni < 8 && nj >= 0 && nj < 8)) break;
//            }
//            if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
//                if ((chess[i][j] < 0 && chess[ni][nj]>0) || (chess[i][j] > 0 && chess[ni][nj] < 0))
//                    drawoutline(window, ni, nj);
//        }
//        ni = i - 1, nj = j + 1;
//        if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
//        {
//            while (chess[ni][nj] == 0)
//            {
//                drawoutline(window, ni, nj);
//                ni--;
//                nj++;
//                if (!(ni >= 0 && ni < 8 && nj >= 0 && nj < 8)) break;
//            }
//            if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
//                if ((chess[i][j] < 0 && chess[ni][nj]>0) || (chess[i][j] > 0 && chess[ni][nj] < 0))
//                    drawoutline(window, ni, nj);
//        }
//
//        ni = i + 1, nj = j - 1;
//        if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
//        {
//            while (chess[ni][nj] == 0)
//            {
//                drawoutline(window, ni, nj);
//                ni++;
//                nj--;
//                if (!(ni >= 0 && ni < 8 && nj >= 0 && nj < 8)) break;
//            }
//            if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
//                if ((chess[i][j] < 0 && chess[ni][nj]>0) || (chess[i][j] > 0 && chess[ni][nj] < 0))
//                    drawoutline(window, ni, nj);
//        }
//
//        ni = i + 1, nj = j + 1;
//        if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
//        {
//            while (chess[ni][nj] == 0)
//            {
//                drawoutline(window, ni, nj);
//                ni++;
//                nj++;
//                if (!(ni >= 0 && ni < 8 && nj >= 0 && nj < 8)) break;
//            }
//            if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
//                if ((chess[i][j] < 0 && chess[ni][nj]>0) || (chess[i][j] > 0 && chess[ni][nj] < 0))
//                    drawoutline(window, ni, nj);
//
//        }
//    }
//    void Initialprint(RenderWindow& window, int i, int j, int** chess) override
//    {
//        if (chess[i][j] < 0)
//        {
//            IPW(window, i, j);
//        }
//        else
//        {
//            IPB(window, i, j);
//        }
//    }
//    void IPW(RenderWindow& window, int i, int j)
//    {
//        Texture texture;
//        Sprite sprite;
//        texture.loadFromFile("bishup w.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 100, i * 100);
//        window.draw(sprite);
//
//    }
//    void IPB(RenderWindow& window, int i, int j)
//    {
//        Texture texture;
//        Sprite sprite;
//        texture.loadFromFile("bishup b.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 100, i * 100);
//        window.draw(sprite);
//
//    }
//
//};
//class rook : public peices
//{
//public:
//    rook() : peices()
//    {
//
//    }
//    ~rook()
//    {
//
//    }
//    bool validationcheck(int fi, int fj, int si, int sj, int** chess)
//    {
//        int ffi = fi, ffj = fj, ssi = si, ssj = sj;
//        if (chess[fi][fj] < 0 && fi >= 0 && fi < 8 && si >= 0 && si < 8 && fj >= 0 && fj < 8 && sj >= 0 && sj < 8)
//        {
//            if (chess[si][sj] == 9) return false; // if it try to kill king 
//            if (chess[si][sj] < 0) return false;
//            if (si != fi && sj != fj) return false;
//
//            if (fi - si > 0)// upside
//            {
//                while (--ffi > si)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                }
//
//            }
//            ffi = fi, ffj = fj, ssi = si, ssj = sj;
//            if (fi - si < 0)//downwards
//            {
//                while (++ffi < si)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                }
//
//            }
//            ffi = fi, ffj = fj, ssi = si, ssj = sj;
//            if (fj - sj > 0)//left
//            {
//                while (--ffj > sj)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                }
//
//            }
//            ffi = fi, ffj = fj, ssi = si, ssj = sj;
//            if (fj - sj < 0)//right
//            {
//                while (++ffj < sj)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                }
//
//            }
//            return true;
//        }
//
//        if (chess[fi][fj] > 0 && fi >= 0 && fi < 8 && si >= 0 && si < 8 && fj >= 0 && fj < 8 && sj >= 0 && sj < 8)
//        {
//            if (chess[si][sj] == -9) return false; // if it try to kill king 
//            if (chess[si][sj] > 0) return false;
//            if (si != fi && sj != fj) return false;
//
//            if (fi - si > 0)// upside
//            {
//                while (--ffi > si)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                }
//
//            }
//            ffi = fi, ffj = fj, ssi = si, ssj = sj;
//            if (fi - si < 0)//downwards
//            {
//                while (++ffi < si)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                }
//
//            }
//            ffi = fi, ffj = fj, ssi = si, ssj = sj;
//            if (fj - sj > 0)//left
//            {
//                while (--ffj > sj)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                }
//
//            }
//            ffi = fi, ffj = fj, ssi = si, ssj = sj;
//            if (fj - sj < 0)//right
//            {
//                while (++ffj < sj)
//                {
//                    if (chess[ffi][ffj] != 0) return false;
//                }
//
//            }
//            return true;
//        }
//    }
//    void futureprint(RenderWindow& window, int i, int j, int** chess)
//    {
//        int n = 0;
//        for (int x = 0; x < 8; x++)
//        {
//            if (this->validationcheck(i, j, n, j, chess))
//            {
//                // draw a yellow outline around the box
//                drawoutline(window, n, j);
//
//            }
//            if (this->validationcheck(i, j, i, n, chess))
//            {
//                // draw a yellow outline around the box
//                drawoutline(window, i, n);
//            }
//            n++;
//        }
//    }
//    void Initialprint(RenderWindow& window, int i, int j, int** chess) override
//    {
//        if (chess[i][j] < 0)
//        {
//            IPW(window, i, j);
//        }
//        else
//        {
//            IPB(window, i, j);
//        }
//    }
//    void IPW(RenderWindow& window, int i, int j)
//    {
//        Texture texture;
//        Sprite sprite;
//        texture.loadFromFile("rook w.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 100, i * 100);
//        window.draw(sprite);
//
//    }
//    void IPB(RenderWindow& window, int i, int j)
//    {
//        Texture texture;
//        Sprite sprite;
//        texture.loadFromFile("rook b.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 100, i * 100);
//        window.draw(sprite);
//
//    }
//};
//class king : public peices
//{
//public:
//    king() : peices()
//    {
//
//    }
//    ~king()
//    {
//
//    }
//    bool validationcheck(int fi, int fj, int si, int sj, int** chess)
//    {
//        int initialPosX = fi - 1, initialPosY = fj - 1;
//        bool possible = 0;
//        if (si < 8 && sj < 8 && si >= 0 && sj >= 0)
//            if (!((chess[fi][fj] > 0 && chess[si][sj] > 0) || (chess[fi][fj] < 0 && chess[si][sj] < 0)))
//            {//if final cords are wihin the scope of board and are of the other colour 
//                if (sj >= initialPosY && sj <= initialPosY + 2 && si >= initialPosX && si <= initialPosX + 2)
//                    possible = 1;
//            }
//        return possible;
//    }
//    void futureprint(RenderWindow& window, int i, int j, int** chess)
//    {
//        int currentPosX = i - 1, currentPosY = j - 1;
//        bool possible = 0;
//        for (int x = 0; x < 3; x++)
//        {//traverse the range of kings movement as a 3X3 matrix
//            for (int y = 0; y < 3; y++)
//            {
//                //&& not check
//                if (validationcheck(i, j, currentPosX + x, currentPosY + y, chess))
//                {
//                    drawoutline(window, currentPosX + x, currentPosY + y);
//                }
//            }
//        }
//    }
//    void Initialprint(RenderWindow& window, int i, int j, int ** chess) override
//    {
//        if (chess[i][j] < 0)
//        {
//            IPW(window, i, j);
//        }
//        else
//        {
//            IPB(window, i, j);
//        }
//    }
//    void IPW(RenderWindow& window, int i, int j)
//    {
//        Texture texture;
//        Sprite sprite;
//        texture.loadFromFile("king w.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 100, i * 100);
//        window.draw(sprite);
//
//    }
//    void IPB(RenderWindow& window, int i, int j)
//    {
//        Texture texture;
//        Sprite sprite;
//        texture.loadFromFile("king b.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 100, i * 100);
//        window.draw(sprite);
//    }
//};
//class queen : public peices
//{
//    rook r;
//    bishup b;
//public:
//    queen() : peices()
//    {
//
//    }
//    ~queen()
//    {
//
//    }
//    bool validationcheck(int fi, int fj, int si, int sj, int** chess)
//    {
//        if (fi >= 0 && fi < 8 && si >= 0 && si < 8 && fj >= 0 && fj < 8 && sj >= 0 && sj < 8)
//        {
//            if (chess[si][sj] == 9 || chess[si][sj] == -9) return false;
//            if (r.validationcheck(fi, fj, si, sj, chess) || b.validationcheck(fi, fj, si, sj, chess))
//            {
//                return true;
//            }
//            return false;
//        }
//    }
//    void futureprint(RenderWindow& window, int i, int j, int** chess)
//    {
//        r.futureprint(window, i, j, chess);
//        b.futureprint(window, i, j, chess);
//    }
//    void Initialprint(RenderWindow& window, int i, int j, int** chess) override
//    {
//        if (chess[i][j] < 0)
//        {
//            IPW(window, i, j);
//        }
//        else
//        {
//            IPB(window, i, j);
//        }
//    }
//    void IPW(RenderWindow& window, int i, int j)
//    {
//        Texture texture;
//        Sprite sprite;
//        texture.loadFromFile("queen w.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 100, i * 100);
//        window.draw(sprite);
//    }
//    void IPB(RenderWindow& window, int i, int j)
//    {
//        Texture texture;
//        Sprite sprite;
//        texture.loadFromFile("queen b.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 100, i * 100);
//        window.draw(sprite);
//    }
//
//};
//class emptycell : public peices
//{
//public:
//    emptycell() : peices()
//    {
//
//    }
//    ~emptycell()
//    {
//
//    }
//    bool validationcheck(int fi, int fj, int si, int sj, int** chess)
//    {
//        return true;
//    }
//    void futureprint(RenderWindow& window, int i, int j, int** chess)
//    {
//        Texture texture;
//        
//        Sprite sprite;
//        sprite.setTexture(texture);
//        if (chess[i][j] == -1)
//        {
//            if (i % 2 == 0 || j % 2 == 0)
//            {
//                texture.loadFromFile("poosiblemoveblue.png");
//                sprite.setTexture(texture);
//                if (chess[i - 1][j] == 0)
//                {
//                    sprite.setPosition((i-1)*100,j*100);
//                    window.draw(sprite);
//                }
//                if (chess[i - 1][j + 1] < 0 && chess[i - 1][j + 1] != 0)
//                {
//                    sprite.setPosition((i - 1) * 100, (j + 1) * 100);
//                    window.draw(sprite);
//                }
//                if (chess[i - 1][j - 1] < 0 && chess[i - 1][j - 1] != 0)
//                {
//                    sprite.setPosition((i - 1) * 100, (j -1 ) * 100);
//                    window.draw(sprite);
//                }
//            }
//            else
//            {
//
//            }
//        }
//    }
//    void Initialprint(RenderWindow& window, int i, int j, int** chess) override
//    {
//       
//    }
//};
//
//class chessboard
//{
//private:
//    bool player1turn = false;
//public:
//    int** chess = NULL;
//    peices*** peicearr = NULL;
//    Font font4;
//    Text text5;
//    Text text6;
//    bool legal1move(int fi, int fj, int** chess, bool player1turn)
//    {
//        if (player1turn == true && chess[fi][fj] > 0)
//        {
//            return true;
//        }
//        else if (player1turn == false && chess[fi][fj] < 0)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//
//    }
//    chessboard()
//    {
//
//        peicearr = new peices * *[8];
//        for (int i = 0; i < 8; i++)
//        {
//            peicearr[i] = new peices * [8]; // The reason we are using a 3d array is that we cannoot create an array 
//            // array of objects That will be assigned to arr[i] because in 2d array 1 array is pointer array secnd array is object array
//            // so what we did is that we created a 3d pointer array in which the 2d array functionality was provided by 1 and 2 pointer array 
//            // and then we assigned an single object to it which were the drived classes of pieces pawn and rook for example.
//            // and we specfically needed that that the each cell is to be pointed by an pointer so we can call virtual functions.
//        }
//        // ---------------------------
//        chess = new int* [8];
//        for (int i = 0; i < 8; i++)
//        {
//            chess[i] = new int[8];
//        }
//        chess[0][0] = 8;
//        chess[0][1] = 3;
//        chess[0][2] = 7;
//        chess[0][3] = 6;
//        chess[0][4] = 9;
//        chess[0][5] = 7;
//        chess[0][6] = 3;
//        chess[0][7] = 8;
//        //-----------
//        for (int i = 1; i < 7; i++)
//        {
//            for (int j = 0; j < 8; j++)
//            {
//                if (i == 1)
//                {
//                    chess[i][j] = 1;
//                }
//                else if (i == 6)
//                {
//                    chess[i][j] = -1;
//                    chess[7][j] = chess[0][j] * -1;
//                }
//                else
//                {
//                    chess[i][j] = 0;
//                }
//            }
//        }
//        chess[7][3] = -6;
//        chess[7][4] = -9;
//        transform(chess);
//
//    }
//    ~chessboard()
//    {
//        for (int i = 0; i < 8; i++)
//        {
//            for (int j = 0; j < 8; j++)
//            {
//                delete[] peicearr[i][j];
//            }
//            delete[] peicearr[i];
//        }
//        peicearr = NULL;
//    }
//    void transform(int** chessa)
//    {
//        for (int i = 0; i < 8; i++)
//        {
//            for (int j = 0; j < 8; j++)
//            {
//                if (chessa[i][j] == 1 || chessa[i][j] == -1)
//                {
//                    peicearr[i][j] = new Pawn;
//                }
//                else if (chessa[i][j] == 3 || chessa[i][j] == -3)
//                {
//                    peicearr[i][j] = new knight;
//                }
//                else if (chessa[i][j] == 7 || chessa[i][j] == -7)
//                {
//                    peicearr[i][j] = new bishup;
//                }
//                else if (chessa[i][j] == 8 || chessa[i][j] == -8)
//                {
//                    peicearr[i][j] = new rook;
//                }
//                else if (chessa[i][j] == 9 || chessa[i][j] == -9)
//                {
//                    peicearr[i][j] = new king;
//                }
//                else if (chessa[i][j] == 6 || chessa[i][j] == -6)
//                {
//                    peicearr[i][j] = new queen;
//                }
//                else
//                {
//                    peicearr[i][j] = new emptycell;
//                }
//
//            }
//
//        }
//    }
//    void getname(RenderWindow& window, Event& event,string &name)
//    {
//        Font fontname;
//        fontname.loadFromFile("res2/arial.ttf");
//        sf::Text text;
//        text.setFont(fontname);
//        text.setCharacterSize(24);
//        text.setFillColor(sf::Color::Black);
//        text.setPosition(50.f, 50.f);
//
//        if (event.type == sf::Event::TextEntered)
//        {
//            if (event.text.unicode < 128 && event.text.unicode != 13) // Accept ASCII characters except enter key
//            {
//                name += static_cast<char>(event.text.unicode);
//                text.setString(name);
//            }
//            else if (event.text.unicode == 13) // Enter key pressed
//            {
//                
//
//            }
//        }
//        window.draw(text);
//    }
//    void printChess(RectangleShape  board[][8], RenderWindow& window, Texture texture)
//    {
//        // exit function
//        bool isWhite = false;
//        for (int i = 0; i < 8; i++)
//        {
//            for (int j = 0; j < 8; j++)
//            {
//                board[i][j].setSize(sf::Vector2f(100, 100));
//                board[i][j].setPosition(j * 100, i * 100);
//
//                if (isWhite)
//                {
//                    board[i][j].setFillColor(sf::Color::Blue);
//                    board[i][j].setOutlineThickness(-2);
//                    board[i][j].setOutlineColor(Color::Cyan);
//                }
//                else
//                {
//                    board[i][j].setFillColor(sf::Color::White);
//                }
//
//                isWhite = !isWhite;
//
//                window.draw(board[i][j]);
//
//                Sprite sprite;
//                peicearr[i][j]->Initialprint(window, i, j, chess);
//                
//                int x = 0, y = 0;
//                /////////////////////////////////////////////////////
//
//
//            }
//
//            isWhite = !isWhite;
//        }
//        // to indicate player 2 and his total points
//        // 
//        font4.loadFromFile("res2/chessdisplay.ttf");
//        text5.setFont(font4);
//        static int firststart = 1;
//        text5.setString("Player 2");
//        text5.setCharacterSize(64);
//        if (player1turn|| firststart >0)
//        {
//            text5.setFillColor(Color::Red);
//            text5.setOutlineThickness(3);
//        }
//        else
//        {
//            text5.setFillColor(Color:: Black);
//        }
//        text5.setOutlineColor(Color::Cyan);
//        text5.setPosition(930.f, 0.0f);
//        window.draw(text5);
//        // get to the exit
//        Texture EBtexture;
//        EBtexture.loadFromFile("EXIT.png");
//        Sprite exitbutton;
//        exitbutton.setTexture(EBtexture);
//        exitbutton.setPosition(875.f, 375.f);
//        window.draw(exitbutton);
//        //---------
//        Texture savetexture;
//        savetexture.loadFromFile("Save.png");
//        Sprite savebutton;
//        savebutton.setTexture(savetexture);
//        savebutton.setPosition(1025.f, 375.f);
//        window.draw(savebutton);
//        
//        // Player 1 
//        font4.loadFromFile("res2/chessdisplay.ttf");
//        text6.setFont(font4);
//        text6.setString("Player 1");
//        text6.setCharacterSize(64);
//        if (!player1turn)
//        {
//            text6.setFillColor(Color::Red);
//            text6.setOutlineThickness(3);
//            firststart = 0;
//        }
//        else
//        {
//            text6.setFillColor(Color::Black);
//        }
//        text6.setOutlineColor(Color::Cyan);
//        text6.setOutlineThickness(3);
//        text6.setPosition(930.f, 700.f);
//        window.draw(text6);
//
//        
//    }   
//    bool Check(int** board, bool PlayerTurn) {
//
//        int NumberedBoard[8][8] = {}; int index = 1;
//        bool white_turn, black_turn;
//        int white_x_cord, white_y_cord;
//        int black_x_cord, black_y_cord;
//
//        //Numbered Board for Validation check of Pieces in terms of numbered offsets [AKA da suck deez nutz method]
//        for (int i = 0; i < 8; i++)
//            for (int j = 0; j < 8; j++)
//                NumberedBoard[i][j] = index++;
//
//        //Determines position of White and Black King
//        for (int i = 0; i < 8; i++) {
//            for (int j = 0; j < 8; j++) {
//                if (board[i][j] == -6) //White King
//                {
//                    white_x_cord = i; white_y_cord = j;
//                }
//                if (board[i][j] == 6) //Black King
//                {
//                    black_x_cord = i; black_y_cord = j;
//                }
//            }
//        }
//
//        //Determine whose turn it is upon movement
//        if (PlayerTurn) { white_turn = true; black_turn = false; }
//        else { white_turn = false; black_turn = true; }
//
//        if (white_turn) {
//
//            //Diagonal [Bishop, Queen]
//            int NumberedPositionofKing = NumberedBoard[black_x_cord][black_y_cord];
//
//            //Case 1: 
//            for (int i = 1; (log10(NumberedPositionofKing - (i * 9)) + 1 != 1) || (NumberedPositionofKing - (i * 9) - 1) % 8 != 0; i++) {
//                if (board[black_x_cord - i][black_y_cord - i] == -6 || board[black_x_cord - i][black_y_cord - i] == -7) {
//                    return 1;
//                }
//            }
//            //Case 2:
//            for (int i = 1; (log10(NumberedPositionofKing - (i * 7)) + 1 != 1) || (NumberedPositionofKing - (i * 7)) % 8 != 0; i++) {
//                if (board[black_x_cord - i][black_y_cord + i] == -6 || board[black_x_cord - i][black_y_cord + i] == -7) {
//                    return 1;
//                }
//            }
//            //Case 3:
//            for (int i = 1; (NumberedPositionofKing + (i * 7) - 1) % 8 != 0 || ((NumberedPositionofKing + (i * 7)) <= 57); i++) {
//                if (board[black_x_cord + i][black_y_cord - i] == -6 || board[black_x_cord + i][black_y_cord - i] == -7) {
//                    return 1; //Illegal Move
//                }
//            }
//            //Case 4:
//            for (int i = 1; ((NumberedPositionofKing + (i * 9)) <= 57) || ((NumberedPositionofKing + (i * 9)) % 8 == 0); i++) {
//                if (board[black_x_cord + i][black_y_cord + i] == -6 || board[black_x_cord + i][black_y_cord + i] == -7) {
//                    return 1;
//                }
//            }
//
//            //Vertical & Horizonatal [Rook, Queen]
//            for (int i = 0; i < 8; i++) {
//                //Vertical
//                if (board[black_x_cord][i] != 0) {
//                    if (board[i][black_x_cord] == -6 || board[i][black_x_cord] == -9)
//                        return 1;
//                }
//                //Horizontal
//                else if (board[i][black_y_cord] != 0) {
//                    if (board[black_y_cord][i] == -6 || board[black_y_cord][i] == -9)
//                        return 1;
//                }
//            }
//            //Knight
//            int KnightOffsets[8] = { -17, -10, 6, 15, 17, 10, -6, -15 };
//            for (int i = 0; i < 8; i++)
//                KnightOffsets[i] += NumberedPositionofKing;
//
//            for (int i = 0; i < 8; i++) {
//                if (KnightOffsets[i] >= 1 && KnightOffsets[i] <= 64) {
//                    int temp_x = 0, temp_y = 0;
//                    for (int i = 0; i < 8; i++) {
//                        for (int j = 0; j < 8; j++) {
//                            if (NumberedBoard[i][j] == NumberedPositionofKing) {
//                                temp_x = i, temp_y = j;
//                            }
//                        }
//                        if (board[temp_x][temp_y] == 3) {
//                            return 1;
//                        }
//                    }
//                }
//            }
//            return 0;
//        }
//        else if (!black_turn) {
//
//            //Diagonal [Bishop, Queen]
//            int NumberedPositionofKing = NumberedBoard[white_x_cord][white_y_cord];
//
//            //Case 1: 
//            for (int i = 1; (log10(NumberedPositionofKing - (i * 9)) + 1 != 1) || (NumberedPositionofKing - (i * 9) - 1) % 8 != 0; i++) {
//                if (board[white_x_cord - i][white_y_cord - i] == 6 || board[white_x_cord - i][white_y_cord - i] == 7) {
//                    return 1; //Illegal Move
//                }
//            }
//            //Case 2:
//            for (int i = 1; (log10(NumberedPositionofKing - (i * 7)) + 1 != 1) || (NumberedPositionofKing - (i * 7)) % 8 != 0; i++) {
//                if (board[white_x_cord - i][white_y_cord + i] == 6 || board[white_x_cord - i][white_y_cord + i] == 7) {
//                    return 1; //Illegal Move
//                }
//            }
//            //Case 3:
//            for (int i = 1; (NumberedPositionofKing + (i * 7) - 1) % 8 != 0 || ((NumberedPositionofKing + (i * 7)) <= 57); i++) {
//                if (board[white_x_cord + i][white_y_cord - i] == 6 || board[white_x_cord + i][white_y_cord - i] == 7) {
//                    return 1; //Illegal Move
//                }
//            }
//            //Case 4:
//            for (int i = 1; ((NumberedPositionofKing + (i * 9)) <= 57) || ((NumberedPositionofKing + (i * 9)) % 8 == 0); i++) {
//                if (board[white_x_cord + i][white_y_cord + i] == 6 || board[white_x_cord + i][white_y_cord + i] == 7) {
//                    return 1; //Illegal Move
//                }
//            }
//
//            //Vertical & Horizonatal [Rook, Queen]
//            for (int i = 0; i < 8; i++) {
//                //Vertical
//                if (board[white_x_cord][i] != 0) {
//                    if (board[i][white_x_cord] == 6 || board[i][white_x_cord] == 9) {
//                        return 1; //Illegal Move 
//                    }
//                }
//                //Horizontal
//                else if (board[i][white_y_cord] != 0) {
//                    if (board[white_y_cord][i] == 6 || board[white_y_cord][i] == 9) {
//                        return 1; //Illegal Move
//                    }
//                }
//            }
//
//            //Knight
//            int KnightOffsets[8] = { -17, -10, 6, 15, 17, 10, -6, -15 };
//            for (int i = 0; i < 8; i++)
//                KnightOffsets[i] += NumberedPositionofKing;
//
//            for (int i = 0; i < 8; i++) {
//                if (KnightOffsets[i] >= 1 && KnightOffsets[i] <= 64) {
//                    int temp_x = 0, temp_y = 0;
//                    for (int i = 0; i < 8; i++) {
//                        for (int j = 0; j < 8; j++) {
//                            if (NumberedBoard[i][j] == NumberedPositionofKing) {
//                                temp_x = i, temp_y = j;
//                            }
//                        }
//                        if (board[temp_x][temp_y] == -3) {
//                            return 1;
//                        }
//                    }
//                }
//            }
//            return 0;
//        }
//    }
//    void chessmovment(Event event, RenderWindow& window, int& fj, int& fi, int& sj, int& si, bool& pause, int& choice)
//    {
//        static bool checksss = false , cv=true;
//        static int whitekingX = 0, whitekingY = 0, blackkingX, blackkingY = 0, u = 0;
//        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//        {
//           
//                int x = Mouse::getPosition(window).x;
//                int y = Mouse::getPosition(window).y;
//               
//                if (x >= 875.0f && x <= 975.0f && y >= 370.0f && y <= 423.0f)
//                {
//                    player1turn = false;
//                    for (int i = 0; i < 8; i++)
//                    {
//                        chess[i] = new int[8];
//                    }
//                    chess[0][0] = 8;
//                    chess[0][1] = 3;
//                    chess[0][2] = 7;
//                    chess[0][3] = 6;
//                    chess[0][4] = 9;
//                    chess[0][5] = 7;
//                    chess[0][6] = 3;
//                    chess[0][7] = 8;
//                    //-----------
//                    for (int i = 1; i < 7; i++)
//                    {
//                        for (int j = 0; j < 8; j++)
//                        {
//                            if (i == 1)
//                            {
//                                chess[i][j] = 1;
//                            }
//                            else if (i == 6)
//                            {
//                                chess[i][j] = -1;
//                                chess[7][j] = chess[0][j] * -1;
//                            }
//                            else
//                            {
//                                chess[i][j] = 0;
//                            }
//                        }
//                    }
//                    chess[7][3] = -6;
//                    chess[7][4] = -9;
//                    transform(chess);
//                    choice = 0;
//                }
//                else if (x >= 1025.0f && x <= 1125.0f && y >= 370.0f && y <= 423.0f)
//                {
//                    choice = 6; // 2 represenyts choice for load game and 6 reprzents choice for save game
//                }
//            
//        }
//        if (checksss == false)
//        {
//            if (cv == false) // Jis Player ki turn hai uska king highiligh karna hai check implimented true if check is on 
//            {
//                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//                {
//
//                    fj = Mouse::getPosition(window).x;
//                    fi = Mouse::getPosition(window).y;
//
//                    fj /= 100;
//                    fi /= 100;
//                    cout << fi << "\t\t" << fj << endl;
//                    
//                    if (chess[fi][fj] == 0)
//                    {
//                        Font font1;
//                        font1.loadFromFile("res/IceCold.ttf");
//                        Text text1;
//                        text1.setFont(font1);
//                        text1.setString("Select peice");
//                        text1.setCharacterSize(84);
//                        text1.setFillColor(Color::Black);
//                        text1.setOutlineColor(Color::Green);
//                        text1.setOutlineThickness(3);
//                        text1.setPosition(150.f, 350.f);
//                        window.draw(text1);
//                        pause = true;
//                    }
//                    else if (legal1move(fi, fj, chess, player1turn))
//                    {
//                        u++;
//                    }
//                    else
//                    {
//                        Font font1;
//                        font1.loadFromFile("res/IceCold.ttf");
//                        Text text1;
//                        text1.setFont(font1);
//                        text1.setString("Not your turn");
//                        text1.setCharacterSize(64);
//                        text1.setFillColor(Color::Black);
//                        text1.setOutlineColor(Color::Green);
//                        text1.setOutlineThickness(3);
//                        text1.setPosition(150.f, 350.f);
//                        window.draw(text1);
//                        pause = true;
//                    }
//                }
//                if (choice != 0 && (fi < 8 && fj < 8))
//                {
//                    if (!player1turn)
//                    {
//                        if (chess[fi][fj] < 0)
//                        {
//                            peicearr[fi][fj]->futureprint(window, fi, fj, chess);
//                        }
//                    }
//                    else
//                    {
//                        if (chess[fi][fj] > 0)
//                        {
//                            peicearr[fi][fj]->futureprint(window, fi, fj, chess);
//                        }
//                    }
//
//                }
//                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right && u > 0)
//                {
//                    u = 0;
//                    sj = Mouse::getPosition(window).x;
//                    si = Mouse::getPosition(window).y;
//                    sj /= 100;
//                    si /= 100;
//
//                    cout << "zohaib";
//                    cout << si << "\t\t" << sj << endl;
//                   
//                        if (peicearr[fi][fj]->validationcheck(fi, fj, si, sj, chess))
//                        {
//                            if (chess[fi][fj] == 9)
//                            {
//                                whitekingX = si;
//                                whitekingY = sj;
//                            }
//                            if (chess[fi][fj] == -9)
//                            {
//                                blackkingX = si;
//                                blackkingY = sj;
//                            }
//                            chess[si][sj] = chess[fi][fj];
//                            chess[fi][fj] = 0;
//                            transform(chess);
//                            if (cv == true)
//                            {
//                                /* chess[fi][fj] = chess[si][sj];
//                                 chess[si][sj] = 0;
//                                 transform(chess);*/
//                               /* cv = true;*/
//                                player1turn = !player1turn;
//                            }
//                            else
//                            {
//                                Font font1;
//                                font1.loadFromFile("res/IceCold.ttf");
//                                Text text1;
//                                text1.setFont(font1);
//                                text1.setString("Illegal check Move 1");
//                                text1.setCharacterSize(64);
//                                text1.setFillColor(Color::Black);
//                                text1.setOutlineColor(Color::Green);
//                                text1.setOutlineThickness(3);
//                                text1.setPosition(150.f, 350.f);
//                                window.draw(text1);
//                                pause = true;
//                                chess[fi][fj] = chess[si][sj];
//                                chess[si][sj] = 0; // The peices need to be exchanged
//                                transform(chess);
//
//                            }
//                        }
//
//                        else
//                        {
//                            Font font1;
//                            font1.loadFromFile("res/IceCold.ttf");
//                            Text text1;
//                            text1.setFont(font1);
//                            text1.setString("Illegal check Move");
//                            text1.setCharacterSize(64);
//                            text1.setFillColor(Color::Black);
//                            text1.setOutlineColor(Color::Green);
//                            text1.setOutlineThickness(3);
//                            text1.setPosition(150.f, 350.f);
//                            window.draw(text1);
//                            pause = true;
//
//                        }
//                    
//                }
//            }
//            else 
//            {
//                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//                {
//                    Sprite Hover;
//                    Texture Thover;
//                    
//                    
//
//                    
//                    fj = Mouse::getPosition(window).x;
//                    fi = Mouse::getPosition(window).y;
//                    fj /= 100;
//                    fi /= 100;
//                    cout << fi << "\t\t" << fj << endl;
//                    if (chess[fi][fj] == 0)
//                    {
//                        Font font1;
//                        font1.loadFromFile("res/IceCold.ttf");
//                        Text text1;
//                        text1.setFont(font1);
//                        text1.setString("Select peice");
//                        text1.setCharacterSize(84);
//                        text1.setFillColor(Color::Black);
//                        text1.setOutlineColor(Color::Green);
//                        text1.setOutlineThickness(3);
//                        text1.setPosition(150.f, 350.f);
//                        window.draw(text1);
//                        pause = true;
//                    }
//                    else if (legal1move(fi, fj, chess, player1turn))
//                    {
//                        u++;
//                    }
//                    else
//                    {
//                        Font font1;
//                        font1.loadFromFile("res/IceCold.ttf");
//                        Text text1;
//                        text1.setFont(font1);
//                        text1.setString("Not your turn");
//                        text1.setCharacterSize(64);
//                        text1.setFillColor(Color::Black);
//                        text1.setOutlineColor(Color::Green);
//                        text1.setOutlineThickness(3);
//                        text1.setPosition(150.f, 350.f);
//                        window.draw(text1);
//                        pause = true;
//                    }
//                }
//                if (choice != 0 && (fi < 8 && fj < 8))
//                {
//                    if (!player1turn)
//                    {
//                        if (chess[fi][fj]<0)
//                        {
//                            peicearr[fi][fj]->futureprint(window, fi, fj, chess);
//                        }
//                    }
//                    else
//                    {
//                        if (chess[fi][fj] > 0)
//                        {
//                            peicearr[fi][fj]->futureprint(window, fi, fj, chess);
//                        }
//                    }
//                    
//                }
//                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right && u > 0)
//                {
//                    u = 0;
//                    sj = Mouse::getPosition(window).x;
//                    si = Mouse::getPosition(window).y;
//                    sj /= 100;
//                    si /= 100;
//
//                    cout << "zohaib";
//                    cout << si << "\t\t" << sj << endl;
//
//                    if (peicearr[fi][fj]->validationcheck(fi, fj, si, sj, chess))
//                    {
//                        chess[si][sj] = chess[fi][fj];
//                        chess[fi][fj] = 0;
//                        transform(chess);
//                        player1turn = !player1turn;
//                    }
//                    else
//                    {
//                        Font font1;
//                        font1.loadFromFile("res/IceCold.ttf");
//                        Text text1;
//                        text1.setFont(font1);
//                        text1.setString("Illegal Move");
//                        text1.setCharacterSize(64);
//                        text1.setFillColor(Color::Black);
//                        text1.setOutlineColor(Color::Green);
//                        text1.setOutlineThickness(3);
//                        text1.setPosition(150.f, 350.f);
//                        window.draw(text1);
//                        pause = true;
//
//                    }
//                }
//            }
//            
//        }
//        else
//        {
//        cout << "Game ended" << endl;
//        }
//        //else if (checkmate==true)
//        //{
//        //    // Printe Check Mate and end the game 
//        //    //Ending game ki logic mai khod impleent kar do ga 
//        //}
//
//
//
//    }//Left clicl Right click wali
//};
//class mainmenu
//{
//    Font font1, font2; // you can load sprites from same font
//    Text text1, text2, text3, text4, text5;
//    RectangleShape background1, background2, background3, background4,background5;
//    Texture menu,loading, texture3, texture4, texture5,uffant,zohaibt,danisht;
//    Sprite uffan, zohaib, danish;
//
//
//public:
//    mainmenu()
//    {
//        font1.loadFromFile("res2/chessdisplay.ttf");
//        font2.loadFromFile("res/IceCold.ttf");
//        /*"res/IceCold.ttf"*/
//        background1.setSize(Vector2f(1200.0f, 800.0f));
//        background2.setSize(Vector2f(1200.0f, 800.0f));
//        background3.setSize(Vector2f(1200.0f, 800.0f));
//        background4.setSize(Vector2f(1200.0f, 800.0f));
//        background5.setSize(Vector2f(1200.0f, 800.0f));
//        menu.loadFromFile("menuimage.png");
//        loading.loadFromFile("loading.png");
//        //texture2.loadFromFile(""); // To get the name;
//        //texture3.loadFromFile("");
//        //texture4.loadFromFile("");
//        //texture5.loadFromFile("");
//        background1.setTexture(&menu);
//        background2.setTexture(&loading);
//      /* background3.setTexture(&texture3);
//        background4.setTexture(&texture4);
//        background5.setTexture(&texture5);*/
//       /* uffant.loadFromFile("");
//        zohaibt.loadFromFile("");
//        danisht.loadFromFile("");
//        uffan.setTexture(uffant);
//        zohaib.setTexture(zohaibt);
//        danish.setTexture(danisht);*/
//        text1.setFont(font2);
//        text2.setFont(font2);
//        text3.setFont(font2);
//        text4.setFont(font2);
//        text5.setFont(font2);
//
//
//    }
//    ~mainmenu()
//    {
//
//    }
//    void printingmenu(RenderWindow& window, Event& event,int & choice)
//    {
//        // Printing of menu screen
//        Vector2i mousepos;
//        mousepos = Mouse::getPosition(window);
//        window.draw(background1);
//        text1.setCharacterSize(50);
//        text1.setString("New Game");
//        if (mousepos.y >= 150.0f && mousepos.y <= 210.0f && mousepos.x >= 475.0f && mousepos.x <= 745.0f)
//        {
//            text1.setFillColor(Color::Yellow); 
//        }
//        else text1.setFillColor(Color::White);
//        text1.setOutlineThickness(2);
//        text1.setOutlineColor(Color::Red);
//        text1.setPosition(Vector2f(475.0f, 150.0f));
//        window.draw(text1);
//        text2.setCharacterSize(50);
//        text2.setString("Load Game");
//        if (mousepos.y >= 260.0f && mousepos.y <= 305.0f && mousepos.x >= 454.0f && mousepos.x <= 760.0f) text2.setFillColor(Color::Yellow);
//        else text2.setFillColor(Color::White);
//        text2.setOutlineThickness(2);
//        text2.setOutlineColor(Color::Red);
//        text2.setPosition(Vector2f(455.0f, 250.0f));
//        window.draw(text2);
//        text3.setCharacterSize(50);
//        text3.setString("Legacy");
//        if (mousepos.y >= 358.0f && mousepos.y <= 406.0f && mousepos.x >= 494.0f && mousepos.x <= 715.0f) text3.setFillColor(Color::Yellow);
//        else text3.setFillColor(Color::White);
//        text3.setOutlineThickness(2);
//        text3.setOutlineColor(Color::Red);
//        text3.setPosition(Vector2f(495.0f, 350.0f));
//        window.draw(text3);
//        text4.setCharacterSize(50);
//        text4.setString("Instructions");
//        if (mousepos.y >= 461.0f && mousepos.y <= 506.0f && mousepos.x >= 403.0f && mousepos.x <= 803.0f) text4.setFillColor(Color::Yellow); 
//        else text4.setFillColor(Color::White);
//        text4.setOutlineThickness(2);
//        text4.setOutlineColor(Color::Red);
//        text4.setPosition(Vector2f(405.0f, 450.0f));
//        window.draw(text4);
//        text5.setCharacterSize(50);
//        text5.setString("Credts");
//        if (mousepos.y >= 558.0f && mousepos.y <= 605.0f && mousepos.x >= 494.0f && mousepos.x <= 715.0f) text5.setFillColor(Color::Yellow); 
//        else text5.setFillColor(Color::White);
//        text5.setOutlineThickness(2);
//        text5.setOutlineColor(Color::Red);
//        text5.setPosition(Vector2f(495.0f, 550.0f));
//        window.draw(text5);
//        //-----------------
//
//        // To identify which option user has selected
//        mousepos = Mouse::getPosition(window);
//        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//        {
//            mousepos = Mouse::getPosition(window);
//            if (mousepos.y >= 150.0f && mousepos.y <= 210.0f && mousepos.x >= 475.0f && mousepos.x <= 745.0f) choice = 1;
//            if (mousepos.y >= 260.0f && mousepos.y <= 305.0f && mousepos.x >= 454.0f && mousepos.x <= 760.0f) choice = 2;
//            if (mousepos.y >= 358.0f && mousepos.y <= 406.0f && mousepos.x >= 494.0f && mousepos.x <= 715.0f) choice = 3;
//            if (mousepos.y >= 461.0f && mousepos.y <= 506.0f && mousepos.x >= 403.0f && mousepos.x <= 803.0f) choice = 4;
//            if (mousepos.y >= 558.0f && mousepos.y <= 605.0f && mousepos.x >= 494.0f && mousepos.x <= 715.0f) choice = 5;
//        }
//
//    }
//   
//    void printingloadingscreen(RenderWindow& window, Event& event, int & choice,int & slotchoice)
//    {
//        window.draw(background2);
//
//        Texture exit;
//        RectangleShape slot1, slot2, slot3;
//        Vector2i mousepos;
//        mousepos = Mouse::getPosition(window); // to change the colours of solt upon hovering of mouse
//        Texture EBtexture;
//        EBtexture.loadFromFile("EXIT.png");
//        Sprite exitbutton;
//        exitbutton.setTexture(EBtexture);
//        exitbutton.setPosition(275.0f, 600.0f);
//        window.draw(exitbutton);
//        Text textforslot1;
//        textforslot1.setFont(font1);
//        textforslot1.setString("SLOT1");
//        slot1.setSize(Vector2f(250.0f, 50.0f));
//        slot1.setFillColor(Color::Green);
//        slot1.setPosition(Vector2f(200.0f, 150.0f));
//        textforslot1.setPosition(Vector2f(290.0f, 155.0f));
//        if (mousepos.y >= 150.0f && mousepos.y <= 200.0f && mousepos.x >= 200.0f && mousepos.x <= 450.0f)
//        {
//            slot1.setFillColor(Color::White);
//        }
//        else if (/*slot is full*/true)slot1.setFillColor(Color::Cyan);
//        else
//        {
//            slot1.setFillColor(Color::Green);
//        }
//        textforslot1.setLetterSpacing(5);
//        textforslot1.setOutlineThickness(3);
//        textforslot1.setOutlineColor(Color::Black);
//        //slot1.setPosition
//        
//        window.draw(slot1);
//        window.draw(textforslot1);
//        //-------------
//        Text textforslot2;
//        textforslot2.setFont(font1);
//        textforslot2.setString("SLOT2");
//        slot2.setSize(Vector2f(250.0f, 50.0f));
//        
//        slot2.setPosition(Vector2f(200.0f, 300.0f));
//        textforslot2.setPosition(Vector2f(290.0f, 305.0f));
//        if (mousepos.y >= 300.0f && mousepos.y <= 350.0f && mousepos.x >= 200.0f && mousepos.x <= 450.0f)
//        {
//            slot2.setFillColor(Color::White);
//        }
//        else if (/*slot is full*/true)slot2.setFillColor(Color::Cyan);
//        else
//        {
//            slot3.setFillColor(Color::Green);
//        }
//       
//        textforslot2.setLetterSpacing(5);
//        textforslot2.setOutlineThickness(3);
//        textforslot2.setOutlineColor(Color::Black);
//        //slot1.setPosition
//
//        window.draw(slot2);
//        window.draw(textforslot2);
//        //----------
//        Text textforslot3;
//        textforslot3.setFont(font1);
//        textforslot3.setString("SLOT3");
//        slot3.setSize(Vector2f(250.0f, 50.0f));
//        slot3.setPosition(Vector2f(200.0f, 450.0f));
//        textforslot3.setPosition(Vector2f(290.0f, 455.0f));
//        if (mousepos.y >= 450.0f && mousepos.y <= 500.0f && mousepos.x >= 200.0f && mousepos.x <= 450.0f)
//        {
//            slot3.setFillColor(Color::White);
//        }
//        else if (/*slot is full*/true)slot3.setFillColor(Color::Cyan);
//        else
//        {
//            slot3.setFillColor(Color::Green);
//        }
//        textforslot3.setLetterSpacing(5);
//        textforslot3.setOutlineThickness(3);
//        textforslot3.setOutlineColor(Color::Black);
//        //slot1.setPosition
//
//        window.draw(slot3);
//        window.draw(textforslot3);
//        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//        {
//            mousepos = Mouse::getPosition(window);
//
//            if (mousepos.y >= 150.0f && mousepos.y <= 200.0f && mousepos.x >= 200.0f && mousepos.x <= 450.0f) slotchoice = 1;
//            else if (mousepos.y >= 300.0f && mousepos.y <= 350.0f && mousepos.x >= 200.0f && mousepos.x <= 450.0f)  slotchoice = 2;
//            else  if (mousepos.y >= 450.0f && mousepos.y <= 500.0f && mousepos.x >= 200.0f && mousepos.x <= 450.0f)  slotchoice = 3;
//            else  if (mousepos.y >= 600.0f && mousepos.y <= 650.0f && mousepos.x >= 275.0f && mousepos.x <= 350.0f)  slotchoice = 4;
//        }
//    }
//    void loadingandsavingfromfile(int & slotchoice,int ** chess,int & choice,chessboard & C1)
//    {
//        if (slotchoice==1 && choice==2) // && and it is not empty 
//        {
//            // load into chess from file 1
//            choice = 1;
//            slotchoice = 0;
//            cout << "hi";
//        }
//        else if (slotchoice == 2 && choice == 2) /*&& it is not empty*/
//        {
//            // load into chess from file 2
//            choice = 1;
//            slotchoice = 0;
//        }
//        else if (slotchoice == 3 && choice == 2) /*&& it is not empty*/
//        {
//            // load into chess from file 3
//            choice = 1;
//            cout << choice;
//            slotchoice = 0;
//        }
//        // you also have to initalise the array to its deafult placement AFTER saving the current game into file
//        if (slotchoice == 1 && choice == 6) // && and it is  empty 
//        {
//            // save into chess from file 1
//            choice = 0;
//            slotchoice = 0;
//            // SAVE HERE
//            for (int i = 0; i < 8; i++)
//            {
//                chess[i] = new int[8];
//            }
//            chess[0][0] = 8;
//            chess[0][1] = 3;
//            chess[0][2] = 7;
//            chess[0][3] = 6;
//            chess[0][4] = 9;
//            chess[0][5] = 7;
//            chess[0][6] = 3;
//            chess[0][7] = 8;
//            //-----------
//            for (int i = 1; i < 7; i++)
//            {
//                for (int j = 0; j < 8; j++)
//                {
//                    if (i == 1)
//                    {
//                        chess[i][j] = 1;
//                    }
//                    else if (i == 6)
//                    {
//                        chess[i][j] = -1;
//                        chess[7][j] = chess[0][j] * -1;
//                    }
//                    else
//                    {
//                        chess[i][j] = 0;
//                    }
//                }
//            }
//            chess[7][3] = -6;
//            chess[7][4] = -9;
//            C1.transform(chess);
//            choice = 0;
//        }
//        else if (slotchoice == 2 && choice == 6) /*&& it is empty*/
//        {
//            // save into chess from file 2
//            choice = 0;
//            slotchoice = 0;
//        }
//        else if (slotchoice == 3 && choice ==6) /*&& it is empty*/
//        {
//            // save into chess from file 3
//            choice = 0;
//            cout << choice;
//            slotchoice = 0;
//        }
//        else if (slotchoice==4)
//        {
//            choice = 0; /// returning to the menu in next iteration
//            cout << choice;
//            slotchoice = 0;
//        }
//    }
//   
//};
//
//int main()
//{
//    mainmenu M1;
//    chessboard C1;
//    int fj = 0, fi = 0, sj = 0, si = 0, p = 0, a = 0, c = 0,x=0,slotchoice=0;
//    bool trrr = false;
//    string name1, name2;
//    RenderWindow window(sf::VideoMode(1200, 800), "Chess Board");
//    window.setFramerateLimit(120);
//    RectangleShape board[8][8];
//    Texture texture;
//    bool pause = false;
//    static int choiceofmenu = 0;
//
//    while (window.isOpen())
//    {
//        // save load load dat into 2d pointer arrayy
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
//        }
//        window.clear();
//        if (choiceofmenu == 0)
//        {
//            M1.printingmenu(window, event, choiceofmenu);
//        }
//        else if (choiceofmenu == 1)
//        {
//            /*if (x==0)
//            {
//                C1.getname(window, event, name1);
//                x++;
//            }
//            */
//            if (pause == true)
//            {
//                sleep(milliseconds(500));
//            }
//            pause = false;
//            C1.printChess(board, window, texture);
//            C1.chessmovment(event, window, fj, fi, sj, si, pause,choiceofmenu);
//        }
//        else if (choiceofmenu  == 2 || choiceofmenu == 6)
//        {
//            M1.printingloadingscreen(window,event,choiceofmenu,slotchoice);
//            M1.loadingandsavingfromfile(slotchoice, C1.chess,choiceofmenu,C1);
//            //choice Ka function sahi karna hai ??
//        }
//        window.display();
//    }
//    
//    // For testing purpose
//    for (int i = 0; i < 8; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            cout << C1.chess[i][j] << "  ";
//        }
//        cout << endl;
//    }
//    system("pause");
//    return 0;
//}
