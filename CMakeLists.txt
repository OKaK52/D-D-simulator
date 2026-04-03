add_executable(SESC_Core
        main.cpp
        Field.cpp
        Hero.cpp          # ЭТОТ ФАЙЛ ДОЛЖЕН БЫТЬ!
        Species.cpp
        CombatClass.cpp
        Cage.h            # .h файлы тоже можно добавить
        # Dice.cpp        # если есть
        # Enemy.cpp       # если есть
)