#include "Point.hpp"

// Funzione che calcola il prodotto vettoriale per determinare il "segno" dell'area del triangolo formato dai  tre punti.
Fixed sign(Point const p1, Point const p2, Point const p3) {
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

// Funzione che verifica se il punto è all'interno del triangolo
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed x, y, z;

	x = sign(point, a, b);
	y = sign(point, b, c);
	z = sign(point, c, a);

	// Verifica se i segni sono coerenti per tutti i prodotti vettoriali
	bool hasNeg = (x.toFloat() < 0) || (y.toFloat() < 0) || (z.toFloat() < 0);
	bool hasPos = (x.toFloat() > 0) || (y.toFloat() > 0) || (z.toFloat() > 0);

	// Il punto è dentro solo se tutti i segni sono coerenti
	return !(hasNeg && hasPos);
}
