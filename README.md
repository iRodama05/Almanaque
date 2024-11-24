# Almanaque PvZ
Este es un sistema para gestionar un almanaque de plantas y zombis inspirado en el juego "Plantas vs. Zombis". El programa permite agregar plantas de diferentes tipos (ofensivas, defensivas, especiales) y zombis, visualizarlos en el almanaque, y realizar otras operaciones como la adición de nuevos elementos.
## Estructura
El proyecto está compuesto por las siguientes clases principales:
### Clases Principales:
Planta: Clase base abstracta para representar las plantas en el juego. Contiene propiedades comunes como nombre, vida, y coste.
PlantaOfensiva: Derivada de Planta, representa las plantas que infligen daño a los zombis. Incluye la propiedad ataque.
PlantaDefensiva: Derivada de Planta, representa las plantas que tienen una función defensiva, como la producción de soles o la resistencia a los ataques. Incluye la propiedad funcion.
PlantaEspecial: Derivada de Planta, representa plantas que tienen efectos especiales, como modificar otras plantas o aplicar efectos a los zombis. Contiene las propiedades modifica_a y efecto.
Zombie: Representa a los zombis en el juego. Incluye propiedades como nombre, vida, y ataque.
Almanaque: Clase encargada de gestionar las plantas y zombis en el juego. Permite agregar elementos al almanaque, mostrar información de las plantas y zombis, y gestionar las relaciones entre ellos.
### Relaciones entre clases:
PlantaEspecial puede depender de una planta base específica (por ejemplo, un Girasol), lo que significa que una planta especial debe plantarse sobre una planta base específica.
La relación entre PlantaEspecial y PlantaBase (como PlantaOfensiva o PlantaDefensiva) tiene una multiplicidad de 1..1 en el lado de la planta especial, y 0..1 en el lado de la planta base.
## Funcionalidades
El programa permite realizar las siguientes operaciones:

• Ver las plantas por categoría (Ofensivas, Defensivas, Especiales).

• Ver todos los zombis disponibles.

• Agregar nuevas plantas y zombis al almanaque.
