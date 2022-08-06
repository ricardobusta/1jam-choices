//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#ifndef INC_1JAMCHOICES_GAMECONFIG_H
#define INC_1JAMCHOICES_GAMECONFIG_H

#include <hge/configuration.h>

namespace Jam {

    class GameConfig {
    public:
        static void Configure(Harpia::Configuration &configuration);
    };

} // Jam

#endif //INC_1JAMCHOICES_GAMECONFIG_H
