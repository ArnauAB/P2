PAV - P2: detección de actividad vocal (VAD)
============================================

Esta práctica se distribuye a través del repositorio GitHub [Práctica 2](https://github.com/albino-pav/P2),
y una parte de su gestión se realizará mediante esta web de trabajo colaborativo.  Al contrario que Git,
GitHub se gestiona completamente desde un entorno gráfico bastante intuitivo. Además, está razonablemente
documentado, tanto internamente, mediante sus [Guías de GitHub](https://guides.github.com/), como
externamente, mediante infinidad de tutoriales, guías y vídeos disponibles gratuitamente en internet.


Inicialización del repositorio de la práctica.
----------------------------------------------

Para cargar los ficheros en su ordenador personal debe seguir los pasos siguientes:

*	Abra una cuenta GitHub para gestionar esta y el resto de prácticas del curso.
*	Cree un repositorio GitHub con el contenido inicial de la práctica (sólo debe hacerlo uno de los
	integrantes del grupo de laboratorio, cuya página GitHub actuará de repositorio central del grupo):
	-	Acceda la página de la [Práctica 2](https://github.com/albino-pav/P2).
	-	En la parte superior derecha encontrará el botón **`Fork`**. Apriételo y, después de unos segundos,
		se creará en su cuenta GitHub un proyecto con el mismo nombre (**P2**). Si ya tuviera uno con ese 
		nombre, se utilizará el nombre **P2-1**, y así sucesivamente.
*	Habilite al resto de miembros del grupo como *colaboradores* del proyecto; de este modo, podrán
	subir sus modificaciones al repositorio central:
	-	En la página principal del repositorio, en la pestaña **:gear:`Settings`**, escoja la opción 
		**Collaborators** y añada a su compañero de prácticas.
	-	Éste recibirá un email solicitándole confirmación. Una vez confirmado, tanto él como el
		propietario podrán gestionar el repositorio, por ejemplo: crear ramas en él o subir las
		modificaciones de su directorio local de trabajo al repositorio GitHub.
*	En la página principal del repositorio, localice el botón **Branch: master** y úselo para crear
	una rama nueva con los primeros apellidos de los integrantes del equipo de prácticas separados por
	guion (**fulano-mengano**).
*	Todos los miembros del grupo deben realizar su copia local en su ordenador personal.
	-	Copie la dirección de su copia del repositorio apretando en el botón **Clone or download**.
		Asegúrese de usar *Clone with HTTPS*.
	-	Abra una sesión de Bash en su ordenador personal y vaya al directorio **PAV**. Desde ahí, ejecute:

		```.sh
		git clone dirección-del-fork-de-la-práctica
		```

	-	Vaya al directorio de la práctica `cd P2`.

	-	Cambie a la rama **fulano-mengano** con la orden:

		```.sh
		git checkout fulano-mengano
		```

*	A partir de este momento, todos los miembros del grupo de prácticas pueden trabajar en su directorio
	local del modo habitual, usando el repositorio remoto en GitHub como repositorio central para el trabajo colaborativo
	de los distintos miembros del grupo de prácticas o como copia de seguridad.
	-	Puede *confirmar* versiones del proyecto en su directorio local con las órdenes siguientes:

		```.sh
		git add .
		git commit -m "Mensaje del commit"
		```

	-	Las versiones confirmadas, y sólo ellas, se almacenan en el repositorio y pueden ser accedidas en cualquier momento.

*	Para interactuar con el contenido remoto en GitHub es necesario que los cambios en el directorio local estén confirmados.

	-	Puede comprobar si el directorio está *limpio* (es decir, si la versión actual está confirmada) usando el comando
		`git status`.

	-	La versión actual del directorio local se sube al repositorio remoto con la orden:

		```.sh
		git push
		```

		*	Si el repositorio remoto contiene cambios no presentes en el directorio local, `git` puede negarse
			a subir el nuevo contenido.

			-	En ese caso, lo primero que deberemos hacer es incorporar los cambios presentes en el repositorio
				GitHub con la orden `git pull`.

			-	Es posible que, al hacer el `git pull` aparezcan *conflictos*; es decir, ficheros que se han modificado
				tanto en el directorio local como en el repositorio GitHub y que `git` no sabe cómo combinar.

			-	Los conflictos aparecen marcados con cadenas del estilo `>>>>`, `<<<<` y `====`. Los ficheros correspondientes
				deben ser editados para decidir qué versión preferimos conservar. Un editor avanzado, del estilo de Microsoft
				Visual Studio Code, puede resultar muy útil para localizar los conflictos y resolverlos.

			-	Tras resolver los conflictos, se ha de confirmar los cambios con `git commit` y ya estaremos en condiciones
				de subir la nueva versión a GitHub con el comando `git push`.


	-	Para bajar al directorio local el contenido del repositorio GitHub hay que ejecutar la orden:

		```.sh
		git pull
		```
	
		*	Si el repositorio local contiene cambios no presentes en el directorio remoto, `git` puede negarse a bajar
			el contenido de este último.

			-	La resolución de los posibles conflictos se realiza como se explica más arriba para
				la subida del contenido local con el comando `git push`.



*	Al final de la práctica, la rama **fulano-mengano** del repositorio GitHub servirá para remitir la
	práctica para su evaluación utilizando el mecanismo *pull request*.
	-	Vaya a la página principal de la copia del repositorio y asegúrese de estar en la rama
		**fulano-mengano**.
	-	Pulse en el botón **New pull request**, y siga las instrucciones de GitHub.


Entrega de la práctica.
-----------------------

Responda, en este mismo documento (README.md), los ejercicios indicados a continuación. Este documento es
un fichero de texto escrito con un formato denominado _**markdown**_. La principal característica de este
formato es que, manteniendo la legibilidad cuando se visualiza con herramientas en modo texto (`more`,
`less`, editores varios, ...), permite amplias posibilidades de visualización con formato en una amplia
gama de aplicaciones; muy notablemente, **GitHub**, **Doxygen** y **Facebook** (ciertamente, :eyes:).

En GitHub. cuando existe un fichero denominado README.md en el directorio raíz de un repositorio, se
interpreta y muestra al entrar en el repositorio.

Debe redactar las respuestas a los ejercicios usando Markdown. Puede encontrar información acerca de su
sintáxis en la página web [Sintaxis de Markdown](https://daringfireball.net/projects/markdown/syntax).
También puede consultar el documento adjunto [MARKDOWN.md](MARKDOWN.md), en el que se enumeran los
elementos más relevantes para completar la redacción de esta práctica.

Recuerde realizar el *pull request* una vez completada la práctica.

Ejercicios
----------

### Etiquetado manual de los segmentos de voz y silencio

- Etiquete manualmente los segmentos de voz y silencio del fichero grabado al efecto. Inserte, a 
  continuación, una captura de `wavesurfer` en la que se vea con claridad la señal temporal, el contorno de
  potencia y la tasa de cruces por cero, junto con el etiquetado manual de los segmentos.

![image](https://github.com/user-attachments/assets/45d77e81-527a-497b-ab41-0d5ed801011c)
![image](https://github.com/user-attachments/assets/f5fb26f2-2522-47a8-aa45-3a08486ef134)

- A la vista de la gráfica, indique qué valores considera adecuados para las magnitudes siguientes:
  
	* Incremento del nivel potencia en dB, respecto al nivel correspondiente al silencio inicial, para
	  estar seguros de que un segmento de señal se corresponde con voz.  
  	_Utilizando el wavesurfer podemos observar la waveform de la señal con su potencia correspondiente (en dBs) y vemos que en las tramas de voz la potencia es de entorno a los 30 dB superior al nivel de silencio inicial de 40dB._

	* Duración mínima razonable de los segmentos de voz y silencio.  
	_La duración de un segmento de voz tiene que ser, como mínimo, el promedio de la duración de una palabra monosilábica pronunciada en castellano en tono normal. Por otro lado, un segmento de silencio tiene que tener una duración necesaria para que las personas lo detectemos naturalmente como silencio, es decir, que sea superior al tiempo de reacción auditiva humana. Ambas duraciones mencionadas están entorno a los 200 ms, comprobamos que este valor es correcto midiendo los timestamps de los tramas de voz y los silencios, así que usaremos este umbral._

	* ¿Es capaz de sacar alguna conclusión a partir de la evolución de la tasa de cruces por cero?<br>
	_Observando la gráfica de los cruces por cero observamos que los periodos donde esta se mantiene elevada suele coincidir con periodos de silencio en la señal, esto de debe a que es una grabación imperfecta y el ruido blanco que existe de fondo tiende a ser aleatorio y oscilatorio, aumentando este índice. Aún así no obtenemos una polarización perfecta, también hay tramos de señal de voz que pueden tener un número de cruces por cero notable debido a sonidos sordos o fricativos (s o f), ruido de fondo y interferencias entre otros motivos._


### Desarrollo del detector de actividad vocal
![image](https://github.com/user-attachments/assets/3e0ade58-4556-48dc-abbe-a08459a4c21c)

- Complete el código de los ficheros de la práctica para implementar un detector de actividad vocal en
  tiempo real tan exacto como sea posible. Tome como objetivo la maximización de la puntuación-F `TOTAL`.  
_Con el código desarrollado, procedemos a evaluar el rendimiento utilizando el script `vad_evaluation.pl`, lo que nos permite calcular el valor de 'Recall'. Este parámetro mide la proporción de muestras correctamente detectadas por nuestro algoritmo en relación con las muestras marcadas de "Ground Truth". Por otro lado, 'Precision' refleja la proporción de las muestras detectadas por nuestro algoritmo que efectivamente corresponden a actividad vocal. La media armónica de estos valores da lugar al F-score, que evalúa el equilibrio entre 'Recall' y 'Precision'. Tras la evaluación, logramos un valor de F-score de 93,016%, un resultado muy bueno de la detección de actividad vocal._

- Inserte una gráfica en la que se vea con claridad la señal temporal, el etiquetado manual y la detección
  automática conseguida para el fichero grabado al efecto.  
  _Esta es la señal grabada, con las transcripciones de etiquetado manual (.lab superior) y las de detección del algoritmo (.vad inferior)._  
![image](https://github.com/user-attachments/assets/f321f637-2638-46e3-8fe9-b9ee955c95db)
![image](https://github.com/user-attachments/assets/e5a79eb2-1c37-46e7-9955-540cd89d6bc1)

- Explique, si existen. las discrepancias entre el etiquetado manual y la detección automática.  
_En las imágenes capturadas de wavesurfer observamos como nuestro programa discierne con alta precisión entre los tramos de voz y los de silencio, excepto en un caso en concreto alrededor del segundo 6,6 donde se introduce un corto segmento de silencio debido a que la palabra "dia" se alarga más de lo normal mientras se atenúa y vibra la voz, lo cual confunde al algoritmo._

- Evalúe los resultados sobre la base de datos `db.v4` con el script `vad_evaluation.pl` e inserte a 
  continuación las tasas de sensibilidad (*recall*) y precisión para el conjunto de la base de datos (sólo
  el resumen).  
  _Después de haber optimizado los parámetros de alpha1, alpha2 y Tmin (8.3, 2.6 y 11 respectivamente), al ejecutar el algoritmo sobre todas las señales de la base de datos proporcionada de cursos anteriores, acabamos obteniendo un F-score elevado de 91.263%._  
![image](https://github.com/user-attachments/assets/9e47c536-aed3-4254-bf12-062061b8a105)


### Trabajos de ampliación

#### Cancelación del ruido en los segmentos de silencio

- Si ha desarrollado el algoritmo para la cancelación de los segmentos de silencio, inserte una gráfica en
  la que se vea con claridad la señal antes y después de la cancelación (puede que `wavesurfer` no sea la
  mejor opción para esto, ya que no es capaz de visualizar varias señales al mismo tiempo).  
_Comparando la waveform de la señal de audio antes y después de aplicar la cancelación de ruido en los segmentos de silencio, observamos como estos tramos vacíos quedan alisados por el hecho de estar sustituyendo este ruido interferente de fondo por un valor 0._  
`ADJUNTAR FOTO DEL WAVESURFER AMB I SENSE CANCEL·LACIÓ DE SOROLL`

#### Gestión de las opciones del programa usando `docopt_c`

- Si ha usado `docopt_c` para realizar la gestión de las opciones y argumentos del programa `vad`, inserte
  una captura de pantalla en la que se vea el mensaje de ayuda del programa.  
_Sí, hemos usado `docopt_c` para realizar la gestión de las opciones y argumentos alpha1 y alpha 2 del programa, de manera que al ejecutar `scripts/run_vad.sh 8.3 2.6` en el terminal, se definen alpha1=8.3 y alpha2=2.6, los cuales hemos visto que optimizaban nuestro algoritmo para un número de tramas fijas Tmin=11._  
![image](https://github.com/user-attachments/assets/02ba9d56-84b8-416c-9d5b-a646f1ce514e)
![image](https://github.com/user-attachments/assets/c2f1ce6a-edd5-4a74-a81d-4157fb74b47d)
![image](https://github.com/user-attachments/assets/27a0c639-ff34-45c4-bcac-8af63b3def12)


### Contribuciones adicionales y/o comentarios acerca de la práctica

- Indique a continuación si ha realizado algún tipo de aportación suplementaria (algoritmos de detección o 
  parámetros alternativos, etc.).

- Si lo desea, puede realizar también algún comentario acerca de la realización de la práctica que
  considere de interés de cara a su evaluación.

### Antes de entregar la práctica

Recuerde comprobar que el repositorio cuenta con los códigos correctos y en condiciones de ser 
correctamente compilados con la orden `meson bin; ninja -C bin`. El programa generado (`bin/vad`) será
el usado, sin más opciones, para realizar la evaluación *ciega* del sistema.
