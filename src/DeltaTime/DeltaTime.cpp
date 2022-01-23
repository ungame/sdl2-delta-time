#include "DeltaTime.hpp"

#include <SDL2/SDL.h>

DeltaTime::DeltaTime()
{

}

// DeltaTime->compute: 
// Recebe o tempo em milissegundos que um frame demorou para completar.
// Para calcular o frameTime, faça: SDL_GetTicks() - lastTime;
// SDL_GetTicks retorna o tempo em milissegundos desde que a biblioteca foi inicializada.

// No exemplo abaixo vamos assumir que o lastTime recebeu 200, ou seja,
// fazem 200 milissegundos que a SDL foi inicializada:

//      float lastTime = (float) SDL_GetTicks(); 
//      while(true)
//      {
//          inputs...
//          updates...
//          draw...
//  
//          float frameTime = SDL_GetTicks() - lastTime;          
//      }
//
// neste exemplo na segunda chamada de SDL_GetTicks() se passaram 3 milissegundos,
// isso significa que o frameTime recebeu: 203 - 200, ou seja,
// o frameTime demorou 3 milissegundos para completar. 
//
// com o tempo do frame em mãos, agora precisaremos normalizar o tempo
// para que ele respeite o FPS que desejamos, neste caso 60 FPS.

// Para que um jogo rode a 60 FPS, é necessário que o tempo que 1 frame
// demora para completar seja de 16,67 milissegundos aproximados, que é o mesmo que
// dividir 1000 milissegundos por 60.

// Neste caso, se o frameTime for exatamente 16,67 milissegundos,
// o deltaTime será 16,67 * (60 / 1000) = 1,0002, ou seja,
// tudo que estiver em movimento e for multiplicado pelo deltaTime,
// se moverá exatamente no valor especificado, pois será multiplicado por 1;

// Agora vamos assumir que um objeto esteja em uma cordenada X, Y na tela, 
// sendo o valor de X = 1, e Y = 0, e uma velocidade constante de 1, ex:
 
// float x = x + 1 * deltaTime;

// Se o deltaTime for 1,0002, então o objeto irá mover para o pixel 2 do eixo X, ou seja,
// x vai receber 1 + 1 * 1,0002 que é igual à: 2,004 
// Obs: (a parte decimal será removida se X for usado como inteiro)

// Se o frameTime for apenas 3 milissegundos, o deltaTime será: 0.18, ou seja
// float deltaTime = 3 * (60 / 1000)

// Ao tentar mover o objeto mais vez:

// x = x + 1 * 0.18, que neste exemplo é o mesmo que x recebe 2 + 1 * 0.18; A próxima posição
// de X será: 0,54. Neste caso o objeto irá se mover um pouco mais que meio pixel no próximo frame.

// Na próxima atualização, o tempo do frameTime foi de 5 milissegundos:

// float deltaTime = 5 * (60 / 1000) = 0,3

// Agora vamos calcular novamente a posição do objeto no próximo frame:

// x = x + 1 * 0.3, que neste exemplo é o mesmo que x recebe 0.54 + 1 * 0.3, a próxima posição
// de X será: 3. Agora sim o objeto alcançou o pixel 3 do eixo X.
// Com isso garantimos que os objetos se movam para uma posição baseado no FPS que desejamos,
// independente do poder de processamento da máquina.
float DeltaTime::compute(float frameTime)
{
    float deltaTime = frameTime * (TARGET_FPS / SECOND_IN_MS);
    
    if (deltaTime > TARGET_DELTATIME)
    {
        return TARGET_DELTATIME;
    }

    return deltaTime;
}