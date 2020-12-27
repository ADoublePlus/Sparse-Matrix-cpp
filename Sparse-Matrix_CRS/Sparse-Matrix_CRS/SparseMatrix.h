#pragma once

#define __SPARSEMATRIX_H__

#include <vector>
#include <iostream>

template <typename T>
class SparseMatrix
{
	public:
		// Creation
		SparseMatrix(int n); // Square matrix nxn
		SparseMatrix(int rows, int columns); // General matrix

		SparseMatrix(const SparseMatrix<T>& m); // Copy constructor
		SparseMatrix<T>& operator=(const SparseMatrix<T>& m);

		~SparseMatrix(void);

		// Getters and setters
		int getRowCount(void) const;
		int getColumnCount(void) const;

		// Values
		T get(int row, int col) const;
		SparseMatrix& set(T val, int row, int col);

		// Operators
		std::vector<T> multiply(const std::vector<T>& x) const;
		std::vector<T> operator*(const std::vector<T>& x) const;

		SparseMatrix<T> multiply(const SparseMatrix<T>& m) const;
		SparseMatrix<T> operator*(const SparseMatrix<T>& m) const;

		SparseMatrix<T> add(const SparseMatrix<T>& m) const;
		SparseMatrix<T> operator+(const SparseMatrix<T>& m) const;

		SparseMatrix<T> subtract(const SparseMatrix<T>& m) const;
		SparseMatrix<T> operator-(const SparseMatrix<T>& m) const;

		// Friend functions
		template <typename X>
		friend bool operator==(const SparseMatrix<X>& a, const SparseMatrix<X>& b);

		template <typename X>
		friend bool operator!=(const SparseMatrix<X>& a, const SparseMatrix<X>& b);

		template <typename X>
		friend std::ostream& operator<<(std::ostream& os, const SparseMatrix<T>& matrix);

	protected:
		int m, n;

		std::vector<T>* vals;
		std::vector<int>* rows, * cols;

		// Helpers and validators
		void construct(int m, int n);
		void destruct(void);
		void deepCopy(const SparseMatrix<T>& m);
		void validateCoordinates(int row, int col) const;
		void insert(int index, int row, int col, T val);
		void remove(int index, int row);
};