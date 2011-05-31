// $Id: LineStringSnapperTest.cpp 2468 2009-05-05 10:14:39Z strk $
// 
// Test Suite for geos::operation::overlay::snap::LineStringSnapper class.

// tut
#include <tut.hpp>
// geos
#include <geos/operation/overlay/snap/LineStringSnapper.h>
#include <geos/geom/Coordinate.h>
#include <geos/geom/CoordinateList.h>
#include <geos/geom/CoordinateArraySequence.h>
// std
#include <string>
#include <vector>

namespace tut
{
    //
    // Test Group
    //

    // Common data used by tests
    struct test_linestringsnapper_data
    {

        test_linestringsnapper_data() {}
    };

    typedef test_group<test_linestringsnapper_data> group;
    typedef group::object object;

    group test_linestringsnapper_group("geos::operation::overlay::snap::LineStringSnapper");

    //
    // Test Cases
    //

    // Test vertices snapping
    template<>
    template<>
    void object::test<1>()
    {
		using geos::geom::Coordinate;
		using geos::operation::overlay::snap::LineStringSnapper;

		typedef std::auto_ptr<Coordinate::Vect> CoordsVectAptr;


		// source coordinates
		Coordinate src_a(0, 0);
		Coordinate src_b(10, 10);

		// snap coordinates
		Coordinate snp_a(0.1, 0);
		Coordinate snp_b(10, 10.1);

		Coordinate::Vect srcCoords;
		srcCoords.push_back( src_a );
		srcCoords.push_back( src_b );

		Coordinate::ConstVect snpCoords;
		snpCoords.push_back( &snp_a );
		snpCoords.push_back( &snp_b );

		LineStringSnapper snapper(srcCoords, 0.4);

		CoordsVectAptr ret(snapper.snapTo(snpCoords));

		// both points should have been snapped
		ensure_equals(ret->operator[](0), snp_a);
		ensure_equals(ret->operator[](1), snp_b);

	}

    // Test segment snapping
    template<>
    template<>
    void object::test<2>()
    {
		using geos::geom::Coordinate;
		using geos::operation::overlay::snap::LineStringSnapper;

		typedef std::auto_ptr<Coordinate::Vect> CoordsVectAptr;


		// source coordinates
		Coordinate src_a(0, 0);
		Coordinate src_b(10, 10);

		// snap coordinates
		Coordinate snp_a(0.4, 0);
		Coordinate snp_b(10, 10.4);

		Coordinate::Vect srcCoords;
		srcCoords.push_back( src_a );
		srcCoords.push_back( src_b );

		Coordinate::ConstVect snpCoords;
		snpCoords.push_back( &snp_a );
		snpCoords.push_back( &snp_b );

		LineStringSnapper snapper(srcCoords, 0.3);

		CoordsVectAptr ret(snapper.snapTo(snpCoords));

		// snap point a should be inserted
		ensure_equals(ret->size(), 3u); 
		ensure_equals(ret->operator[](0), src_a);
		ensure_equals(ret->operator[](1), snp_a);
		ensure_equals(ret->operator[](2), src_b);

	}


} // namespace tut
