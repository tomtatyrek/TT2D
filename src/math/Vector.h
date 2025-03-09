//
// Created by Tomáš Tatyrek on 09/03/2025.
//

#ifndef TT2D_VECTOR_H
#define TT2D_VECTOR_H

#include "defines.h"

namespace TT2D {

	class Vector {

		TT2D_VNTYPE x, y;

	public:
		//Constructors
		Vector();
		Vector(TT2D_VNTYPE x, TT2D_VNTYPE y);

		//Methods
		TT2D_VNTYPE size() const;
		void normalize();

		//Static functions
		static void normalize(Vector& vector);
	};

}

#endif//TT2D_VECTOR_H
