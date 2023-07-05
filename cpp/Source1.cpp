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
//    virtual ~peices() {}
//    virtual void Initialprint(RenderWindow& window, int a, int b, int** chess) = 0;
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
//                if ((fi - si == 2) && (si < fi && sj == fj) && (chess[fi - 2][fj] == 0))
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
//                if ((si - fi == 2) && (fi < si && sj == fj) && chess[fi + 2][fj] == 0)
//                {
//                    return true;
//                }
//                if (si - fi == 1 && (fi < si && sj == fj) && (chess[fi + 1][fj] == 0)) return true;
//            }
//            if (fi != 1)
//            {
//                if ((si - fi == 1) && (fi < si && sj == fj) && chess[fi + 1][fj] == 0)
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
//        texture.loadFromFile("pawn w.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 102, i * 100);
//        window.draw(sprite);
//    }
//    void IPB(RenderWindow& window, int i, int j)
//    {
//        Texture texture;
//        Sprite sprite;
//        texture.loadFromFile("pawn b.png");
//        sprite.setTexture(texture);
//        sprite.setPosition(j * 102, i * 100);
//        window.draw(sprite);
//
//    }
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
//                    sprite.setPosition((i - 1) * 100, j * 100);
//                    window.draw(sprite);
//                }
//                if (chess[i - 1][j + 1] < 0 && chess[i - 1][j + 1] != 0)
//                {
//                    sprite.setPosition((i - 1) * 100, (j + 1) * 100);
//                    window.draw(sprite);
//                }
//                if (chess[i - 1][j - 1] < 0 && chess[i - 1][j - 1] != 0)
//                {
//                    sprite.setPosition((i - 1) * 100, (j - 1) * 100);
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
//class chessboard
//{
//
//public:
//    bool player1turn = false;
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
//    void getname(RenderWindow& window, Event& event, string& name)
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
//        if (player1turn || firststart > 0)
//        {
//            text5.setFillColor(Color::Red);
//            text5.setOutlineThickness(3);
//        }
//        else
//        {
//            text5.setFillColor(Color::Black);
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
//    bool blackCheck(int** board, int bx, int by)
//    {//return true is black king is in check
//        //8 rock
//        //3 knight
//        //7 bishop
//        //6 queen
//        //9 king
//        //1 pawn
//        //white is negative
//        bool ischeck = false;
//        ////for rook and queen////
//        for (int i = 1; i + by < 8; i++)//rightwards
//        {
//            if (board[bx][by + i] > 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[bx][by + i] == -8 || board[bx][by + i] == -6)
//            {//if enemy rook or queen is present
//                return true;
//            }
//        }
//        for (int i = 1; by - i >= 0; i++)//leftwards
//        {
//            if (board[bx][by - i] > 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[bx][by - i] == -8 || board[bx][by - i] == -6)
//            {//if enemy rook or queen is present
//                return true;
//            }
//        }
//        for (int i = 1; bx - i >= 0; i++)//upwards
//        {
//            if (board[bx - i][by] > 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[bx - i][by] == -8 || board[bx][by - i] == -6)
//            {//if enemy rook or queen is present
//                return true;
//            }
//        }
//        for (int i = 1; bx + i < 8; i++)//downwards
//        {
//            if (board[bx + i][by] > 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[bx + i][by] == -8 || board[bx][by - i] == -6)
//            {//if enemy rook or queen is present
//                return true;
//            }
//        }
//        ///bishup and queen///
//        for (int i = 1; by + i < 8 && bx - i >= 0; i++)//up right
//        {
//            if (board[bx - i][by + i] > 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[bx - i][by + i] == -7 || board[bx - i][by + i] == -6)
//            {//if enemy bishup or queen is present
//                return true;
//            }
//
//        }
//        for (int i = 1; by - i >= 0 && bx - i >= 0; i++)//up left
//        {
//            if (board[bx - i][by - i] > 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[bx - i][by - i] == -7 || board[bx - i][by - i] == -6)
//            {//if enemy bishup or queen is present
//                return true;
//            }
//
//        }
//        for (int i = 1; by - i >= 0 && bx + i < 8; i++)//down left
//        {
//            if (board[bx + i][by - i] > 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[bx + i][by - i] == -7 || board[bx + i][by - i] == -6)
//            {//if enemy bishup or queen is present
//                return true;
//            }
//
//        }
//        for (int i = 1; by + i < 8 && bx + i < 8; i++)//down right
//        {
//            if (board[bx + i][by + i] > 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[bx + i][by + i] == -7 || board[bx + i][by + i] == -6)
//            {//if enemy bishup or queen is present
//                return true;
//            }
//
//        }
//        ///knight////
//        if (bx + 2 < 8 && by + 1 < 8)
//        {
//            if (board[bx + 2][by + 1] == -3) return true;
//        }
//        if (bx + 2 < 8 && by - 1 >= 0)
//        {
//            if (board[bx + 2][by - 1] == -3) return true;
//        }
//        if (bx - 2 >= 0 && by + 1 < 8)
//        {
//            if (board[bx - 2][by + 1] == -3) return true;
//        }
//        if (bx - 2 >= 0 && by - 1 >= 0)
//        {
//            if (board[bx - 2][by - 1] == -3) return true;
//        }
//
//        if (bx + 1 < 8 && by + 2 < 8)
//        {
//            if (board[bx + 1][by + 2] == -3) return true;
//        }
//        if (bx - 1 >= 0 && by + 2 < 8)
//        {
//            if (board[bx - 1][by + 2] == -3) return true;
//        }
//        if (bx + 1 < 8 && by - 2 >= 0)
//        {
//            if (board[bx + 1][by - 2] == -3) return true;
//        }
//        if (bx - 1 >= 0 && by - 2 >= 0)
//        {
//            if (board[bx - 1][by - 2] == -3) return true;
//        }
//        ///pawn///
//        if (bx + 1 < 8 && by + 1 < 8)
//        {
//            if (board[bx + 1][by + 1] == -1) return true;
//        }
//        if (bx + 1 < 8 && by - 1 >= 0)
//        {
//            if (board[bx + 1][by - 1] == -1) return true;
//        }
//
//        return ischeck;
//
//    }
//    bool whiteCheck(int** board, int wx, int wy)
//    {//return true if white king is in check
//        bool ischeck = false;
//        ////for rook and queen////
//        for (int i = 1; i + wy < 8; i++)//rightwards
//        {
//            if (board[wx][wy + i] < 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[wx][wy + i] == 8 || board[wx][wy + i] == 6)
//            {//if enemy rook or queen is present
//                return true;
//            }
//        }
//        for (int i = 1; wy - i >= 0; i++)//leftwards
//        {
//            if (board[wx][wy - i] < 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[wx][wy - i] == 8 || board[wx][wy - i] == 6)
//            {//if enemy rook or queen is present
//                return true;
//            }
//        }
//        for (int i = 1; wx - i >= 0; i++)//upwards
//        {
//            if (board[wx - i][wy] < 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[wx - i][wy] == 8 || board[wx][wy - i] == 6)
//            {//if enemy rook or queen is present
//                return true;
//            }
//        }
//        for (int i = 1; wx + i < 8; i++)//upwards
//        {
//            if (board[wx + i][wy] < 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[wx + i][wy] == 8 || board[wx][wy - i] == 6)
//            {//if enemy rook or queen is present
//                return true;
//            }
//        }
//        ///bishup and queen///
//        for (int i = 1; wy + i < 8 && wx - i >= 0; i++)//up right
//        {
//            if (board[wx - i][wy + i] < 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[wx - i][wy + i] == 7 || board[wx - i][wy + i] == 6)
//            {//if enemy bishup or queen is present
//                return true;
//            }
//
//        }
//        for (int i = 1; wy + i < 8 && wx - i >= 0; i++)//down left
//        {
//            if (board[wx - i][wy + i] < 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[wx - i][wy + i] == 7 || board[wx - i][wy + i] == 6)
//            {//if enemy bishup or queen is present
//                return true;
//            }
//
//        }
//        for (int i = 1; wy - i >= 0 && wx + i < 8; i++)//up left
//        {
//            if (board[wx + i][wy - i] < 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[wx + i][wy - i] == 7 || board[wx + i][wy - i] == 6)
//            {//if enemy bishup or queen is present
//                return true;
//            }
//
//        }
//        for (int i = 1; wy + i < 8 && wx + i < 8; i++)//down right
//        {
//            if (board[wx + i][wy + i] < 0)
//            {//if a friendly piece is found
//                break;
//            }
//            else if (board[wx + i][wy + i] == 7 || board[wx + i][wy + i] == 6)
//            {//if enemy bishup or queen is present
//                return true;
//            }
//
//        }
//        ///knight////
//        if (wx + 2 < 8 && wy + 1 < 8)
//        {
//            if (board[wx + 2][wy + 1] == 3) return true;
//        }
//        if (wx + 2 < 8 && wy - 1 >= 0)
//        {
//            if (board[wx + 2][wy - 1] == 3) return true;
//        }
//        if (wx - 2 >= 0 && wy + 1 < 8)
//        {
//            if (board[wx - 2][wy + 1] == 3) return true;
//        }
//        if (wx - 2 >= 0 && wy - 1 >= 0)
//        {
//            if (board[wx - 2][wy - 1] == 3) return true;
//        }
//
//        if (wx + 1 < 8 && wy + 2 < 8)
//        {
//            if (board[wx + 1][wy + 2] == 3) return true;
//        }
//        if (wx - 1 >= 0 && wy + 2 < 8)
//        {
//            if (board[wx - 1][wy + 2] == 3) return true;
//        }
//        if (wx + 1 < 8 && wy - 2 >= 0)
//        {
//            if (board[wx + 1][wy - 2] == 3) return true;
//        }
//        if (wx - 1 >= 0 && wy - 2 >= 0)
//        {
//            if (board[wx - 1][wy - 2] == 3) return true;
//        }
//        ///pawn///
//        if (wx + 1 < 8 && wy + 1 < 8)
//        {
//            if (board[wx + 1][wy + 1] == 1) return true;
//        }
//        if (wx + 1 < 8 && wy - 1 >= 0)
//        {
//            if (board[wx + 1][wy - 1] == 1) return true;
//        }
//
//        return ischeck;
//
//    }
//    bool hasPossiblity(peices*** arr, int** board, int kingx, int kingy, bool player1Turn)
//    {
//        int** temp = new int* [8];
//        for (int i = 0; i < 8; i++)
//        {//temp stores current board
//            temp[i] = new int[8];
//            for (int j = 0; j < 8; j++)
//            {
//                temp[i][j] = board[i][j];
//            }
//        }
//        //traversing pieces arr
//        int temp_piece = 0;
//        bool checkCanBeRemoved = 0;
//        for (int i = 0; i < 8 && !checkCanBeRemoved; i++)
//        {
//            for (int j = 0; j < 8 && !checkCanBeRemoved; j++)
//            {
//                for (int l = 0; l < 8 && !checkCanBeRemoved; l++)
//                {
//                    for (int m = 0; m < 8 && !checkCanBeRemoved; m++)
//                    {
//                        if (arr[i][j]->validationcheck(i, j, l, m, board))
//                        {//if it is a valid move for arr[i][j] then move temp and check for same color check
//                            temp_piece = temp[l][m];
//                            temp[l][m] = board[i][j];
//                            temp[i][j] = 0;
//                            if (!player1turn)
//                            {
//                                checkCanBeRemoved = blackCheck(temp, kingx, kingy);
//                            }
//                            else  checkCanBeRemoved = whiteCheck(temp, kingx, kingy);
//
//                            if (!checkCanBeRemoved)
//                            {//when check cannot be removed then revert the changes
//                                temp[i][j] = temp[l][m];
//                                temp[l][m] = temp_piece;
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        return checkCanBeRemoved;
//    }
//    void chessmovment(Event event, RenderWindow& window, int& fj, int& fi, int& sj, int& si, bool& pause, int& choice,int & eor)
//    {
//        static bool checksss = false, cv = true;
//        static int whitekingX = 7, whitekingY = 4, blackkingX = 0, blackkingY = 4;
//        int kingX = 0, kingY = 0;
//        static int u = 0;
//        bool isINCheck = 0;
//
//        if (player1turn)
//        {//if white moved normally in last turn and put a check on black king
//            isINCheck = blackCheck(chess, blackkingX, blackkingY);
//            kingX = blackkingX;
//            kingY = blackkingY;
//        }
//        else
//        {
//            isINCheck = whiteCheck(chess, whitekingX, whitekingY);
//            kingX = whitekingX;
//            kingY = whitekingY;
//        }
//
//        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//        {
//
//            int x = Mouse::getPosition(window).x;
//            int y = Mouse::getPosition(window).y;
//
//            if (x >= 875.0f && x <= 975.0f && y >= 370.0f && y <= 423.0f)
//            {
//                player1turn = false;
//                for (int i = 0; i < 8; i++)
//                {
//                    chess[i] = new int[8];
//                }
//                chess[0][0] = 8;
//                chess[0][1] = 3;
//                chess[0][2] = 7;
//                chess[0][3] = 6;
//                chess[0][4] = 9;
//                chess[0][5] = 7;
//                chess[0][6] = 3;
//                chess[0][7] = 8;
//                //-----------
//                for (int i = 1; i < 7; i++)
//                {
//                    for (int j = 0; j < 8; j++)
//                    {
//                        if (i == 1)
//                        {
//                            chess[i][j] = 1;
//                        }
//                        else if (i == 6)
//                        {
//                            chess[i][j] = -1;
//                            chess[7][j] = chess[0][j] * -1;
//                        }
//                        else
//                        {
//                            chess[i][j] = 0;
//                        }
//                    }
//                }
//                chess[7][3] = -6;
//                chess[7][4] = -9;
//                transform(chess);
//                choice = 0;
//            }
//            else if (x >= 1025.0f && x <= 1125.0f && y >= 370.0f && y <= 423.0f)
//            {
//                choice = 6; // 2 represenyts choice for load game and 6 reprzents choice for save game
//            }
//
//        }
//        if (isINCheck)//if in check
//        {
//            cout << "\n\n****END\nNEND\nEND\nEND\nEND\nNEND\nEND\nEND\nEND\n****\n\n";
//            drawoutline(window, kingX, kingY);//highlight king if in check
//            if (hasPossiblity(peicearr, chess, kingX, kingY, player1turn))//check is removeable
//            {
//                //take user input
//                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//                {
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
//                    if (peicearr[fi][fj]->validationcheck(fi, fj, si, sj, chess))
//                    {
//
//                        if (chess[fi][fj] == -9)
//                        {
//                            whitekingX = si;
//                            whitekingY = sj;
//                        }
//                        if (chess[fi][fj] == 9)
//                        {
//                            blackkingX = si;
//                            blackkingY = sj;
//                        }
//                        int temp = chess[si][sj];
//                        chess[si][sj] = chess[fi][fj];
//                        chess[fi][fj] = 0;
//                        if (player1turn)
//                        {//if white moved normally in last turn and put a check on black king
//                            isINCheck = blackCheck(chess, blackkingX, blackkingY);
//                            kingX = blackkingX;
//                            kingY = blackkingY;
//                        }
//                        else
//                        {
//                            isINCheck = whiteCheck(chess, whitekingX, whitekingY);
//                            kingX = whitekingX;
//                            kingY = whitekingY;
//                        }
//                        if (isINCheck)
//                        {//revert
//                            chess[fi][fj] = chess[si][sj];
//                            chess[si][sj] = temp;
//                            Font font1;
//                            font1.loadFromFile("res/IceCold.ttf");
//                            Text text1;
//                            text1.setFont(font1);
//                            text1.setString("Illegal check Move 1");
//                            text1.setCharacterSize(64);
//                            text1.setFillColor(Color::Black);
//                            text1.setOutlineColor(Color::Green);
//                            text1.setOutlineThickness(3);
//                            text1.setPosition(150.f, 350.f);
//                            window.draw(text1);
//                            pause = true;
//                            chess[fi][fj] = chess[si][sj];
//                            chess[si][sj] = 0; // The peices need to be exchanged
//                            transform(chess);
//                        }
//                        transform(chess);
//                    }
//                    else
//                    {
//                        Font font1;
//                        font1.loadFromFile("res/IceCold.ttf");
//                        Text text1;
//                        text1.setFont(font1);
//                        text1.setString("Illegal check Move");
//                        text1.setCharacterSize(64);
//                        text1.setFillColor(Color::Black);
//                        text1.setOutlineColor(Color::Green);
//                        text1.setOutlineThickness(3);
//                        text1.setPosition(150.f, 350.f);
//                        window.draw(text1);
//                        pause = true;
//
//                    }
//
//                }
//            }
//            else
//            {
//            cout << " game ended";
//            choice = 7;
//            }
//            //if (choice != 0 && (fi < 8 && fj < 8))
//            //{
//            //    if (!player1turn)
//            //    {
//            //        if (chess[fi][fj]<0)
//            //        {
//            //            peicearr[fi][fj]->futureprint(window, fi, fj, chess);
//            //        }
//            //    }
//            //    else
//            //    {
//            //        if (chess[fi][fj] > 0)
//            //        {
//            //            peicearr[fi][fj]->futureprint(window, fi, fj, chess);
//            //        }
//            //    }
//            //        
//            //}
//            //if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right && u > 0)
//            //{
//            //    u = 0;
//            //    sj = Mouse::getPosition(window).x;
//            //    si = Mouse::getPosition(window).y;
//            //    sj /= 100;
//            //    si /= 100;
//            //    cout << "zohaib";
//            //    cout << si << "\t\t" << sj << endl;
//            //    if (peicearr[fi][fj]->validationcheck(fi, fj, si, sj, chess))
//            //    {
//            //        chess[si][sj] = chess[fi][fj];
//            //        chess[fi][fj] = 0;//updated board after movement
//            //        transform(chess);
//            //        player1turn = !player1turn;
//            //    }
//            //    else
//            //    {
//            //        Font font1;
//            //        font1.loadFromFile("res/IceCold.ttf");
//            //        Text text1;
//            //        text1.setFont(font1);
//            //        text1.setString("Illegal Move");
//            //        text1.setCharacterSize(64);
//            //        text1.setFillColor(Color::Black);
//            //        text1.setOutlineColor(Color::Green);
//            //        text1.setOutlineThickness(3);
//            //        text1.setPosition(150.f, 350.f);
//            //        window.draw(text1);
//            //        pause = true;
//            //      }
//            //    }
//            //}
//
//        }
//        else//play normally
//        {
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//            {
//                fj = Mouse::getPosition(window).x;
//                fi = Mouse::getPosition(window).y;
//                fj /= 100;
//                fi /= 100;
//                cout << fi << "\t\t" << fj << endl;
//                if (chess[fi][fj] == 0)
//                {
//                    Font font1;
//                    font1.loadFromFile("res/IceCold.ttf");
//                    Text text1;
//                    text1.setFont(font1);
//                    text1.setString("Select peice");
//                    text1.setCharacterSize(84);
//                    text1.setFillColor(Color::Black);
//                    text1.setOutlineColor(Color::Green);
//                    text1.setOutlineThickness(3);
//                    text1.setPosition(150.f, 350.f);
//                    window.draw(text1);
//                    pause = true;
//                }
//                else if (legal1move(fi, fj, chess, player1turn))
//                {
//                    u++;
//                }
//                else
//                {
//                    Font font1;
//                    font1.loadFromFile("res/IceCold.ttf");
//                    Text text1;
//                    text1.setFont(font1);
//                    text1.setString("Not your turn");
//                    text1.setCharacterSize(64);
//                    text1.setFillColor(Color::Black);
//                    text1.setOutlineColor(Color::Green);
//                    text1.setOutlineThickness(3);
//                    text1.setPosition(150.f, 350.f);
//                    window.draw(text1);
//                    pause = true;
//                }
//            }
//            if (choice != 0 && (fi < 8 && fj < 8))
//            {
//                if (!player1turn)
//                {
//                    if (chess[fi][fj] < 0)
//                    {
//                        peicearr[fi][fj]->futureprint(window, fi, fj, chess);
//                    }
//                }
//                else
//                {
//                    if (chess[fi][fj] > 0)
//                    {
//                        peicearr[fi][fj]->futureprint(window, fi, fj, chess);
//                    }
//                }
//
//            }
//            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right && u > 0)
//            {
//                u = 0;
//                sj = Mouse::getPosition(window).x;
//                si = Mouse::getPosition(window).y;
//                sj /= 100;
//                si /= 100;
//
//                cout << "zohaib";
//                cout << si << "\t\t" << sj << endl;
//
//                if (peicearr[fi][fj]->validationcheck(fi, fj, si, sj, chess))
//                {
//
//                    if (chess[fi][fj] == -9)
//                    {
//                        whitekingX = si;
//                        whitekingY = sj;
//                    }
//                    if (chess[fi][fj] == 9)
//                    {
//                        blackkingX = si;
//                        blackkingY = sj;
//                    }
//                    chess[si][sj] = chess[fi][fj];
//                    chess[fi][fj] = 0;
//                    transform(chess);
//                    player1turn = !player1turn;
//                }
//                else
//                {
//                    Font font1;
//                    font1.loadFromFile("res/IceCold.ttf");
//                    Text text1;
//                    text1.setFont(font1);
//                    text1.setString("Illegal Move");
//                    text1.setCharacterSize(64);
//                    text1.setFillColor(Color::Black);
//                    text1.setOutlineColor(Color::Green);
//                    text1.setOutlineThickness(3);
//                    text1.setPosition(150.f, 350.f);
//                    window.draw(text1);
//                    pause = true;
//
//                }
//            }
//        }
//
//    }//Left clicl Right click wali
//};
//class mainmenu
//{
//    Font font1, font2; // you can load sprites from same font
//    Text text1, text2, text3, text4, text5;
//    RectangleShape background1, background2, background3, background4, background5, q, w, e, r, t, y;
//    Texture menu, loading, credits, endinggame, instructions, uffant, zohaibt, danisht, t1, t2, t3, t4, t5, t6;
//    Sprite uffan, zohaib, danish;
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
//
//        q.setSize(Vector2f(1200.0f, 800.0f));
//        w.setSize(Vector2f(1200.0f, 800.0f));
//        e.setSize(Vector2f(1200.0f, 800.0f));
//        r.setSize(Vector2f(1200.0f, 800.0f));
//        t.setSize(Vector2f(1200.0f, 800.0f));
//        y.setSize(Vector2f(1200.0f, 800.0f));
//        menu.loadFromFile("menuimage.png");
//        loading.loadFromFile("loading.png");
//        credits.loadFromFile("credits.png");
//        endinggame.loadFromFile("endingscreen.png");
//        instructions.loadFromFile("instructions.png");
//        t1.loadFromFile("inst.jpeg");
//        t2.loadFromFile("rooki.png");
//        t3.loadFromFile("bishopi.png");
//        t4.loadFromFile("knighti.png");
//        t5.loadFromFile("queeni.png");
//        t6.loadFromFile("kingi.png");
//
//        //texture2.loadFromFile(""); // To get the name;
//        //texture3.loadFromFile("");
//        //texture4.loadFromFile("");
//        //texture5.loadFromFile("");
//        background1.setTexture(&menu);
//        background2.setTexture(&loading);
//        background3.setTexture(&credits);
//        background4.setTexture(&endinggame);
//        background5.setTexture(&instructions);
//        q.setTexture(&t1);
//        w.setTexture(&t2);
//        e.setTexture(&t3);
//        r.setTexture(&t4);
//        t.setTexture(&t5);
//        y.setTexture(&t6);
//        /* background3.setTexture(&texture3);
//          background4.setTexture(&texture4);
//          background5.setTexture(&texture5);*/
//          /* uffant.loadFromFile("");
//           zohaibt.loadFromFile("");
//           danisht.loadFromFile("");
//           uffan.setTexture(uffant);
//           zohaib.setTexture(zohaibt);
//           danish.setTexture(danisht);*/
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
//    void printingmenu(RenderWindow& window, Event& event, int& choice)
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
//    void printingloadingscreen(RenderWindow& window, Event& event, int& choice, int& slotchoice)
//    {
//        window.draw(background2);
//        ifstream Slot1_read("Slot1.txt"), Slot2_read("Slot2.txt"), Slot3_read("Slot3.txt");
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
//        slot1.setPosition(Vector2f(200.0f, 150.0f));
//        textforslot1.setPosition(Vector2f(290.0f, 155.0f));
//        if (mousepos.y >= 150.0f && mousepos.y <= 200.0f && mousepos.x >= 200.0f && mousepos.x <= 450.0f)
//        {
//            slot1.setFillColor(Color::White);
//        }
//        else if (Slot1_read.is_open())slot1.setFillColor(Color::Red);
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
//        else if (Slot2_read.is_open())slot2.setFillColor(Color::Red);
//        else
//        {
//            slot2.setFillColor(Color::Green);
//        }
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
//        else if (Slot3_read.is_open()) slot3.setFillColor(Color::Red);
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
//    void loadingandsavingfromfile(int& slotchoice, int** chess, int& choice, chessboard& C1)
//    {
//        ifstream Slot1_read("Slot1.txt"), Slot2_read("Slot2.txt"), Slot3_read("Slot3.txt");
//        if (slotchoice == 1 && choice == 2) // && and it is not empty 
//        {
//            // load into chess from file 1
//            if (!Slot1_read.is_open())
//            {
//                //file is empty, donot allow to open file print the error 
//                cout << "EMpty Empty\n";
//            }
//            else
//            {
//
//                for (int i = 0; i < 8; i++)
//                {
//                    for (int j = 0; j < 8; j++)
//                    {
//                        Slot1_read >> chess[i][j];
//                        cout << chess[i][j] << " ";
//                    }
//                    cout << endl;
//                }
//                Slot1_read.close();
//                choice = 1;
//                cout << choice << " hiiiiiiiiiiiiii\n";
//                cout << chess[2][0] << "\t     hello\n";
//                slotchoice = 0;
//            }
//
//
//        }
//        else if (slotchoice == 2 && choice == 2) // && it is not empty /
//        {
//            // load into chess from file 2
//            if (!Slot2_read.is_open())
//            {
//                //file is empty, donot allow to open file print the error
//                cout << "EMpty Empty\n";
//            }
//            else
//            {
//                for (int i = 0; i < 8; i++)
//                {
//                    for (int j = 0; j < 8; j++)
//                    {
//                        Slot2_read >> chess[i][j];
//                    }
//                }
//                Slot2_read.close();
//                choice = 1;
//                cout << choice;
//                slotchoice = 0;
//            }
//        }
//        else if (slotchoice == 3 && choice == 2) // && it is not empty 
//        {
//            // load into chess from file 3
//
//            if (!Slot3_read.is_open())
//            {
//                //file is empty, donot allow to open file print the error
//            }
//            else
//            {
//                for (int i = 0; i < 8; i++)
//                {
//                    for (int j = 0; j < 8; j++)
//                    {
//                        Slot3_read >> chess[i][j];
//                    }
//                }
//                Slot3_read.close();
//                choice = 1;
//                cout << choice;
//                slotchoice = 0;
//            }
//
//
//
//
//        }
//        // you also have to initalise the array to its deafult placement AFTER saving the current game into file
//        else  if (slotchoice == 1 && choice == 6) // && and it is  empty 
//        {
//
//            ofstream Slot1_write("Slot1.txt");
//            for (int i = 0; i < 8; i++)
//            {
//                for (int j = 0; j < 8; j++)
//                {
//                    Slot1_write << chess[i][j] << " ";
//                }
//                Slot1_write << endl;
//            }
//            Slot1_write.close();
//
//            // save into chess from file 1
//            choice = 0;
//            slotchoice = 0;
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
//        else if (slotchoice == 2 && choice == 6) // && it is empty /
//        {
//            // save into chess from file 2
//            ofstream Slot2_write("Slot2.txt");
//            for (int i = 0; i < 8; i++)
//            {
//                for (int j = 0; j < 8; j++)
//                {
//                    Slot2_write << chess[i][j] << " ";
//                }
//                Slot2_write << endl;
//            }
//            Slot2_write.close();
//
//            // save into chess from file 2
//            choice = 0;
//            slotchoice = 0;
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
//        else if (slotchoice == 3 && choice == 6) // && it is empty /
//        {
//            // save into chess from file 3
//            ofstream Slot3_write("Slot3.txt");
//            for (int i = 0; i < 8; i++)
//            {
//                for (int j = 0; j < 8; j++)
//                {
//                    Slot3_write << chess[i][j] << " ";
//                }
//                Slot3_write << endl;
//            }
//            Slot3_write.close();
//
//            // save into chess from file 3
//            choice = 0;
//            slotchoice = 0;
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
//
//
//            choice = 0;
//        }
//        else if (slotchoice == 4)
//        {
//            choice = 0; /// returning to the menu in next iteration
//            cout << choice;
//            slotchoice = 0;
//        }
//    }
//    void getplayernames(RenderWindow& window, Event& event, string& playername1, string& playername2, int& x)
//    {
//        char inputText[600]{};
//        static int ass = 0;
//        bool entered = false;
//        sf::Font font;
//        if (!font.loadFromFile("res2/chessdisplay.ttf")) {
//            std::cerr << "Failed to load font" << std::endl;
//        }
//
//        sf::RectangleShape inputSlot1(sf::Vector2f(200, 50));
//        inputSlot1.setOutlineThickness(2);
//        inputSlot1.setOutlineColor(Color::Black);
//        inputSlot1.setFillColor(sf::Color::White);
//        inputSlot1.setPosition(100, 100);
//
//        sf::Text text1("Enter Player 1 name", font, 25);
//        /* text1.setString("Enter Player 1 name");
//         text1.setFont(font);
//         text1.setCharacterSize(24);*/
//        text1.setPosition(100, 70);
//
//        Text name1("", font, 25);
//        //  name1.setString("");
//        name1.setPosition(100, 110);
//        //name1.setFont(font);
//        name1.setOutlineColor(Color::Yellow);
//        name1.setOutlineThickness(2);
//        name1.setFillColor(Color::Red);
//
//
//        sf::RectangleShape inputSlot2(sf::Vector2f(200, 50));
//        inputSlot2.setPosition(100, 200);
//        inputSlot2.setFillColor(sf::Color::White);
//
//        // Create two text objects for prompting user to input names
//
//        Text text2("Enter player 2 name:", font, 20);
//        text2.setPosition(100, 170);
//
//        // Create two text objects for displaying the names entered by user
//
//        sf::Text name2("", font, 20);
//        name2.setPosition(100, 210);
//
//
//        if (event.type == sf::Event::TextEntered)
//        {
//            if (event.text.unicode == 8 && ass >= 0 && ass < 600)
//            {
//                inputText[ass--] = '\0';
//                name1.setString(inputText);
//            }
//            if (event.text.unicode < 128)
//            {
//                if (!entered)
//                {
//                    inputText[ass++] += static_cast<char>(event.text.unicode);
//                    name1.setString(inputText);
//                    cout << inputText << endl;
//                    entered = true;
//                }
//            }
//        }
//        if (event.type == sf::Event::KeyReleased)
//        {
//            entered = false;  // set key as released
//        }
//
//
//
//        // Update the text objects to display the current names
//        /*name1.setstring(playername1);
//        name2.setstring(playername2);*/
//
//
//        window.draw(inputSlot1);
//        window.draw(inputSlot2);
//        window.draw(text1);
//        window.draw(text2);
//        window.draw(name1);
//        window.draw(name2);
//
//        // once next is clicked input the value of x as 1
//    }
//    void printingcreditscreen(RenderWindow& window, Event event, int& choiceofmenu)
//    {
//
//        Texture EBtexture;
//        EBtexture.loadFromFile("creditsexit.png");
//        Sprite exitbutton;
//        exitbutton.setTexture(EBtexture);
//        exitbutton.setPosition(1025.0f, 725.0f);
//        window.draw(background3);
//        window.draw(exitbutton);
//
//        Vector2i  mousepos;
//        // background 3 and credits
//
//
//        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//        {
//            mousepos = Mouse::getPosition(window);
//
//
//            if (mousepos.y >= 725.0f && mousepos.y <= 825.0f && mousepos.x >= 1025.0f && mousepos.x <= 1125.0f) choiceofmenu = 0;
//
//        }
//    }
//    void printingendingscreen(RenderWindow& window, Event event, int& choiceofmenu)
//    {
//        Vector2i mousepos;
//        Texture EBtexture;
//        EBtexture.loadFromFile("creditsexit.png");
//        Sprite exitbutton;
//        exitbutton.setTexture(EBtexture);
//        exitbutton.setPosition(1025.0f, 725.0f);
//        window.draw(background4);
//        window.draw(exitbutton);
//
//        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//        {
//            mousepos = Mouse::getPosition(window);
//
//
//            if (mousepos.y >= 725.0f && mousepos.y <= 825.0f && mousepos.x >= 1025.0f && mousepos.x <= 1125.0f) choiceofmenu = 0;
//
//        }
//       
//        
//
//    }
//    void printinginstructionsscreen(RenderWindow& window, Event event, int& choiceofmenu)
//    {
//
//        Vector2i mousepos;
//        window.draw(q);
//        Texture EBstextureq;
//        EBstextureq.loadFromFile("EXIT.png");
//        Sprite exitbuttona;
//        exitbuttona.setTexture(EBstextureq);
//        exitbuttona.setPosition(1025.0f, 725.0f);
//        window.draw(exitbuttona);
//        static int lop = 0;
//        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//        {
//            mousepos = Mouse::getPosition(window);
//
//            if (mousepos.y >= 725.0f && mousepos.y <= 825.0f && mousepos.x >= 1025.0f && mousepos.x <= 1125.0f)
//            {
//                choiceofmenu = 0;
//
//            }
//        }
//    }
//};
//
//
//int main()
//{
//    mainmenu M1;
//    chessboard C1;
//    int fj = 0, fi = 0, sj = 0, si = 0, p = 0, a = 0, c = 0, x = 0, slotchoice = 0,eor=0;
//    bool trrr = false;
//    string Pname1, Pname2;
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
//        if ( choiceofmenu == 0)
//        {
//           
//            M1.printingmenu(window, event, choiceofmenu);
//            x = 0;
//        }
//        else if (choiceofmenu == 1)
//        {
//           /* if (x == 0)
//            {
//               M1.getplayernames(window, event, Pname1, Pname2, x);
//            }*/
//          
//            
//            {
//                if (pause == true)
//                {
//                    sleep(milliseconds(500));
//                }
//                pause = false;
//                C1.printChess(board, window, texture);
//                C1.chessmovment(event, window, fj, fi, sj, si, pause, choiceofmenu,eor);
//               
//            }
//        }
//        else if (choiceofmenu == 2 || choiceofmenu == 6)
//        {
//            x = 0;// so that when they go towards new game the user gets to enter name
//            M1.printingloadingscreen(window, event, choiceofmenu, slotchoice);
//            M1.loadingandsavingfromfile(slotchoice, C1.chess, choiceofmenu, C1);
//            C1.transform(C1.chess);
//            //choice Ka function sahi karna hai ??
//        }
//        else if (choiceofmenu==4)
//        {
//            M1.printinginstructionsscreen(window, event, choiceofmenu);
//        }
//        else if (choiceofmenu==5)
//        {
//           // Vector2i mousepos;
//           M1.printingcreditscreen(window,event,choiceofmenu);
//          /* M1.printingendingscreen(window, event, choiceofmenu);
//           
//           if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//           {
//               mousepos = Mouse::getPosition(window);
//               if (mousepos.y >= 725.0f && mousepos.y <= 825.0f && mousepos.x >= 1025.0f && mousepos.x <= 1125.0f)
//               {
//                   choiceofmenu = 0;
//               }
//           }*/
//        }
//        else if (choiceofmenu == 7)
//        {
//            M1.printingendingscreen(window, event, choiceofmenu);
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
