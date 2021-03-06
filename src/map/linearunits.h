#ifndef LINEARUNITS_H
#define LINEARUNITS_H

#include <cmath>
#include <QDebug>
#include <QPointF>

class LinearUnits
{
public:
	LinearUnits() : _f(NAN) {}
	LinearUnits(int code);

	bool isNull() const {return std::isnan(_f);}
	bool isValid() const {return !std::isnan(_f);}

	double toMeters(double val) const {return val * _f;}
	QPointF toMeters(const QPointF &p) const
	  {return QPointF(p.x() * _f, p.y() * _f);}
	double fromMeters(double val) const {return val / _f;}
	QPointF fromMeters(const QPointF &p) const
	  {return QPointF(p.x() / _f, p.y() /_f);}

	friend bool operator==(const LinearUnits &lu1, const LinearUnits &lu2);
	friend QDebug operator<<(QDebug dbg, const LinearUnits &lu);

private:
	double _f;
};

inline bool operator==(const LinearUnits &lu1, const LinearUnits &lu2)
  {return (lu1._f == lu2._f);}

QDebug operator<<(QDebug dbg, const LinearUnits &lu);

#endif // LINEARUNITS_H
