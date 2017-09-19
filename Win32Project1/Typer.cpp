#include "stdafx.h"
#include <stdexcept>
#include "Typer.h"

char Typer::characterToSym(Typer::Character character)
{
    switch (character) {
    case Typer::Character::a: return 'a';
    case Typer::Character::b: return 'b';
    case Typer::Character::c: return 'c';
    case Typer::Character::d: return 'd';
    case Typer::Character::e: return 'e';
    case Typer::Character::f: return 'f';
    case Typer::Character::g: return 'g';
    case Typer::Character::h: return 'h';
    case Typer::Character::i: return 'i';
    case Typer::Character::j: return 'j';
    case Typer::Character::k: return 'k';
    case Typer::Character::l: return 'l';
    case Typer::Character::m: return 'm';
    case Typer::Character::n: return 'n';
    case Typer::Character::o: return 'o';
    case Typer::Character::p: return 'p';
    case Typer::Character::q: return 'q';
    case Typer::Character::r: return 'r';
    case Typer::Character::s: return 's';
    case Typer::Character::t: return 't';
    case Typer::Character::u: return 'u';
    case Typer::Character::v: return 'v';
    case Typer::Character::w: return 'w';
    case Typer::Character::x: return 'x';
    case Typer::Character::y: return 'y';
    case Typer::Character::z: return 'z';

    case Typer::Character::A: return 'A';
    case Typer::Character::B: return 'B';
    case Typer::Character::C: return 'C';
    case Typer::Character::D: return 'D';
    case Typer::Character::E: return 'E';
    case Typer::Character::F: return 'F';
    case Typer::Character::G: return 'G';
    case Typer::Character::H: return 'H';
    case Typer::Character::I: return 'I';
    case Typer::Character::J: return 'J';
    case Typer::Character::K: return 'K';
    case Typer::Character::L: return 'L';
    case Typer::Character::M: return 'M';
    case Typer::Character::N: return 'N';
    case Typer::Character::O: return 'O';
    case Typer::Character::P: return 'P';
    case Typer::Character::Q: return 'Q';
    case Typer::Character::R: return 'R';
    case Typer::Character::S: return 'S';
    case Typer::Character::T: return 'T';
    case Typer::Character::U: return 'U';
    case Typer::Character::V: return 'V';
    case Typer::Character::W: return 'W';
    case Typer::Character::X: return 'X';
    case Typer::Character::Y: return 'Y';
    case Typer::Character::Z: return 'Z';

    case Typer::Character::_1: return '1';
    case Typer::Character::_2: return '2';
    case Typer::Character::_3: return '3';
    case Typer::Character::_4: return '4';
    case Typer::Character::_5: return '5';
    case Typer::Character::_6: return '6';
    case Typer::Character::_7: return '7';
    case Typer::Character::_8: return '8';
    case Typer::Character::_9: return '9';
    case Typer::Character::_0: return '0';

    case Typer::Character::_TLD: return '~';
    case Typer::Character::_EXC: return '!';
    case Typer::Character::_AT:  return '@';
    case Typer::Character::_SRP: return '#';
    case Typer::Character::_DLR: return '$';
    case Typer::Character::_PRC: return '%';
    case Typer::Character::_HAT: return '^';
    case Typer::Character::_AMP: return '&';
    case Typer::Character::_STR: return '*';
    case Typer::Character::_DSH: return '-';
    case Typer::Character::_UNR: return '_';
    case Typer::Character::_EQ:  return '=';
    case Typer::Character::_PLS: return '+';

    case Typer::Character::_LPR: return '(';
    case Typer::Character::_RPR: return ')';
    case Typer::Character::_LBK: return '[';
    case Typer::Character::_RBK: return ']';
    case Typer::Character::_LBR: return '{';
    case Typer::Character::_RBR: return '}';

    case Typer::Character::_CLN: return ':';
    case Typer::Character::_SCL: return ';';
    case Typer::Character::_CMA: return ',';
    case Typer::Character::_DOT: return '.';
    case Typer::Character::_QUE: return '?';
    case Typer::Character::_SQT: return '\'';
    case Typer::Character::_DQT: return '"';
    case Typer::Character::_FSH: return '/';
    case Typer::Character::_BSH: return '\\';
    case Typer::Character::_MDL: return '|';
    case Typer::Character::_LT:  return '<';
    case Typer::Character::_GT:  return '>';
    default:                     return 'A';
    }
}


Typer::Character Typer::symToCharacter(wchar_t sym)
{
    switch (sym) {
    case 'a': return Typer::Character::a;
    case 'b': return Typer::Character::b;
    case 'c': return Typer::Character::c;
    case 'd': return Typer::Character::d;
    case 'e': return Typer::Character::e;
    case 'f': return Typer::Character::f;
    case 'g': return Typer::Character::g;
    case 'h': return Typer::Character::h;
    case 'i': return Typer::Character::i;
    case 'j': return Typer::Character::j;
    case 'k': return Typer::Character::k;
    case 'l': return Typer::Character::l;
    case 'm': return Typer::Character::m;
    case 'n': return Typer::Character::n;
    case 'o': return Typer::Character::o;
    case 'p': return Typer::Character::p;
    case 'q': return Typer::Character::q;
    case 'r': return Typer::Character::r;
    case 's': return Typer::Character::s;
    case 't': return Typer::Character::t;
    case 'u': return Typer::Character::u;
    case 'v': return Typer::Character::v;
    case 'w': return Typer::Character::w;
    case 'x': return Typer::Character::x;
    case 'y': return Typer::Character::y;
    case 'z': return Typer::Character::z;

    case 'A':  return Typer::Character::A;
    case 'B':  return Typer::Character::B;
    case 'C':  return Typer::Character::C;
    case 'D':  return Typer::Character::D;
    case 'E':  return Typer::Character::E;
    case 'F':  return Typer::Character::F;
    case 'G':  return Typer::Character::G;
    case 'H':  return Typer::Character::H;
    case 'I':  return Typer::Character::I;
    case 'J':  return Typer::Character::J;
    case 'K':  return Typer::Character::K;
    case 'L':  return Typer::Character::L;
    case 'M':  return Typer::Character::M;
    case 'N':  return Typer::Character::N;
    case 'O':  return Typer::Character::O;
    case 'P':  return Typer::Character::P;
    case 'Q':  return Typer::Character::Q;
    case 'R':  return Typer::Character::R;
    case 'S':  return Typer::Character::S;
    case 'T':  return Typer::Character::T;
    case 'U':  return Typer::Character::U;
    case 'V':  return Typer::Character::V;
    case 'W':  return Typer::Character::W;
    case 'X':  return Typer::Character::X;
    case 'Y':  return Typer::Character::Y;
    case 'Z':  return Typer::Character::Z;

    case '1':  return Typer::Character::_1;
    case '2':  return Typer::Character::_2;
    case '3':  return Typer::Character::_3;
    case '4':  return Typer::Character::_4;
    case '5':  return Typer::Character::_5;
    case '6':  return Typer::Character::_6;
    case '7':  return Typer::Character::_7;
    case '8':  return Typer::Character::_8;
    case '9':  return Typer::Character::_9;
    case '0':  return Typer::Character::_0;

    case '~':  return Typer::Character::_TLD;
    case '!':  return Typer::Character::_EXC;
    case '@':  return Typer::Character::_AT;
    case '#':  return Typer::Character::_SRP;
    case '$':  return Typer::Character::_DLR;
    case '%':  return Typer::Character::_PRC;
    case '^':  return Typer::Character::_HAT;
    case '&':  return Typer::Character::_AMP;
    case '*':  return Typer::Character::_STR;
    case '-':  return Typer::Character::_DSH;
    case '_':  return Typer::Character::_UNR;
    case '=':  return Typer::Character::_EQ;
    case '+':  return Typer::Character::_PLS;

    case '(':  return Typer::Character::_LPR;
    case ')':  return Typer::Character::_RPR;
    case '[':  return Typer::Character::_LBK;
    case ']':  return Typer::Character::_RBK;
    case '{':  return Typer::Character::_LBR;
    case '}':  return Typer::Character::_RBR;

    case ':':  return Typer::Character::_CLN;
    case ';':  return Typer::Character::_SCL;
    case ',':  return Typer::Character::_CMA;
    case '.':  return Typer::Character::_DOT;
    case '?':  return Typer::Character::_QUE;
    case '\'': return Typer::Character::_SQT;
    case '"':  return Typer::Character::_DQT;
    case '/':  return Typer::Character::_FSH;
    case '\\': return Typer::Character::_BSH;
    case '|':  return Typer::Character::_MDL;
    case '<':  return Typer::Character::_LT;
    case '>':  return Typer::Character::_GT;
    default:   return Typer::Character::A;
    }
}


void Typer::goToNextChar()
{
    ++this->sequencePos;
    if (this->sequencePos >= Typer::SEQUENCE_SIZE) {
        this->sequencePos = 0;
    }
}



void Typer::calculateSpeed(int charsPerMinute)
{
    std::clock_t end = clock();
    double elapsed_secs = double(end - timeStart) / CLOCKS_PER_SEC;
    
    // TODO: show time remaining on the screen
}


void Typer::calculateAccuracy(double percents)
{
}


Typer::Character Typer::generateRandomTyperCharacter()
{
    //unsigned char upperBound = (unsigned char) Typer::Character::Count;
    unsigned char upperBound = 52;
    unsigned char result = rand() % upperBound;
    return (Typer::Character) result;
}


Typer::Typer()
{
    init();
    
}


char * Typer::getSequence() {
    char * seq = new char [Typer::SEQUENCE_SIZE];
    for (size_t i = 0; i < Typer::SEQUENCE_SIZE; ++i) {
        char index = (i + this->sequencePos) % Typer::SEQUENCE_SIZE;
        Typer::Character ch = this->sequence[index];
        seq[i] = Typer::characterToSym(ch);
    }
    return seq;
}


void Typer::init()
{
    srand((unsigned)time(NULL));
    reset();
}


void Typer::reset()
{
    this->sequencePos = 0;
    this->mistakesCount = 0;
    this->charactersEntered = 0;
    for (int i = 0; i < this->SEQUENCE_SIZE; ++i) {
        this->sequence[i] = this->generateRandomTyperCharacter();
    }
}


void Typer::onInput(Typer::Character character, std::function<void(void)> onRightInput, std::function<void(void)> onWrongInput)
{
    if (!this->started) {
        throw std::logic_error("Typer.onInput() was called before .start() method! Start the game first, and then send the keyboard input to instance");
        return;
    }
    ++this->charactersEntered;
    
    if (this->sequence[sequencePos] == character) {
        onRightInput();
        this->sequence[sequencePos] = this->generateRandomTyperCharacter();
        this->goToNextChar();
    }
    else {
        ++this->mistakesCount;
        onWrongInput();
    }
}


void Typer::start()
{
    this->started = true;
    this->timeStart = clock();
}


void Typer::finish()
{
    this->started = false;
}

//void mainLoop() {
//    MSG message;
//    bool pressed = false;
//    message.message = WM_NULL;
//    while (message.message != WM_QUIT) {
//        while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
//            if (message.message == WM_KEYDOWN) {
//                if (GetAsyncKeyState(0x51) == 0x0001); {
//                    LPCWSTR keyDown = (LPCWSTR)"key pressed \n";
//                    OutputDebugString(keyDown);
//                    pressed = true;
//                }
//            }
//            if (message.message == WM_KEYUP) {
//                if (GetAsyncKeyState(0x51) != 0x0000); {
//                    LPCWSTR keyUp = (LPCWSTR)"key unpressed";
//                    OutputDebugString(keyUp);
//                    pressed = false;
//                }
//            }
//            DispatchMessage(&message);
//        }
//}