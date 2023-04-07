# Laboratorio 1 de SSOO 2

_Primer entregable del laboratorio de la asignatura Sistemas Operativos 2, por Adrián Carrasco Espinosa_

## Ejecución 🚀

Para ejecutar el ejercicio, primero se debe ejecutar el make. Esto creará varios archivos en la carpeta exec. El principal son manager (proceso principal) y el daemon (que se encargará de la copia de seguridad).


Los recursos generados (como el **log.txt**, la **copia de seguridad o backup**, y la carpeta **students** con todos los directorios de los alumnos) se guardarán en la carpeta **output**


Para poder probar el CONTROL + C, que tiene asignado un manejador, se ha incluido una espera de un segundo (sleep(1)) a los procesos PA, PB y PC.


**NOTA:** Es cierto que el header muchilds.h se queda algo corto (sólo dos funciones, que se podrían haber metido en el manager). Esto es porque al igual que el resto de headers, se han hecho con la idea de expandirlos en un futuro. 

