COMPARACIÓN RK4 VS EULER:  RK4 es mucho más estable que Euler, puesto que si deltaT se aumenta un poco, el resultado inmediatamente puede ser completamente erróneo.

DIAGRAMAS DE FASE: RK4 da una elipse, lo cual es de esperar teniendo en cuenta que el sistema NO está recibiendo energía. Euler arroja una elipse-espiral, lo cual indica o que el método está fallando para el deltaT dado (o que mi código está mal).
