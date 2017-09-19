#pragma once
#include <string>
#include <ctime>
#include <functional>

class Typer {
public:
    enum class Character : unsigned char {
        a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        _1, _2, _3, _4, _5, _6, _7, _8, _9, _0,
        _TLD, // ~
        _EXC, // !
        _QUE, // ?
        _AT,  // @
        _SRP, // #
        _DLR, // $ 
        _PRC, // %
        _HAT, // ^
        _AMP, // &
        _STR, // *
        _DSH, // -
        _UNR, // _
        _EQ,  // =
        _PLS, // +
        _LPR, // (
        _RPR, // )
        _LBK, // [
        _RBK, // ]
        _LBR, // {
        _RBR, // }
        _CLN, // :
        _SCL, // ;
        _DOT, // . 
        _CMA, // ,
        _SQT, // '
        _DQT, // "
        _FSH, // /
        _BSH, // \ /
        _MDL, // |
        _LT, // <
        _GT, // >
        Count
    };
    static char characterToSym(Character character);
    static Character symToCharacter(wchar_t sym);

    const static unsigned char SEQUENCE_SIZE = 10;
private:
    bool started = false;
    
    Character sequence [SEQUENCE_SIZE];
    int sequencePos = 0;
    
    std::clock_t timeStart;
    unsigned long long charactersEntered;
    unsigned long long mistakesCount;
    

private:
    void init();
    void goToNextChar();

    
    void calculateSpeed(int charsPerMinute);
    void calculateAccuracy(double percents);
    Character generateRandomTyperCharacter();

public:
    Typer();
    void onInput(Typer::Character character, 
                 std::function<void(void)> onRightInput, 
                 std::function<void(void)> onWrongInput);
    
    char * getSequence();

    void reset();
    void start();
    void finish();

};