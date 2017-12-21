#ifndef EQ_H_
#define EQ_H_

#include <map>
#include <iostream>
#include <utility> // for std::pair
#include <vector>

class Eq
{
public:
	class Expr; //forward declaration
	
	using Row = std::pair<Expr, double>;
	// class Row;                            // forward declaration
	// typedef std::pair<Expr, double> Row;

private:
	int              varnum;
	std::vector<Row> rows;

public:
	class Var 
	{
	private:
		int idx;
	public:
		Var(int idx) : idx(idx) {}
		int getIndex() const { return idx; }
	};

	Eq() : varnum(0) {}
	Var getVar() { return Var(varnum++); }

	class Expr 
	{
		// Expr = num;
		// Expr = Var;
		// Expr = (2*Var;)<-should be an Expr
	private:

		std::map<int, double> e;

	public:
		Expr() = default;
		Expr(const Var& x, double d = 1) { e[x.getIndex()] = d; } // default multiplicator: d (1)

		Expr(const Expr& e) = default;

		Expr& operator+=(const Var &x)
		{
			e[x.getIndex()]++; // default multiplicator: 1
			return *this;
		}

		Expr& operator+=(const Expr &par)
		{
			for (auto x : par.e)
			{
				e[x.first] += x.second;
			}

			return *this;
		}

		void print() const
		{
			for (auto &x : e)
			{
				std::cout << "+ " << x.second << " * x_" << x.first /*<< " "*/;
			}
			//std::cout << std::endl;
		}

	};

	//class Row : public std::pair<Expr, double> {};
	//typedef std::pair<Expr, double> Row;

	Row addEq(const Expr& e, double d = 0)
	{
		Row r = std::pair<Expr, double>(e, d);
		
		rows.push_back(r);

		return r;
	}

	void print() const
	{
		for (const auto &x : rows)
		{
			x.first.print();
			std::cout << " = " << x.second << std::endl;
		}
	}
};

Eq::Expr operator*(double d, const Eq::Var &v) { return (Eq::Expr(v, d)); }

Eq::Expr operator*(const Eq::Var &v, double d) { return (Eq::Expr(v, d)); }

#endif // !EQ_H_

