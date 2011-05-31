// $Id: SegmentPointComparatorTest.cpp 2344 2009-04-09 21:46:30Z mloskot $
// 
// Test Suite for geos::noding::SegmentPointComparator class.

#include <tut.hpp>
// geos
#include <geos/noding/SegmentNode.h>
#include <geos/noding/SegmentString.h>
#include <geos/geom/Coordinate.h>
#include <geos/geom/CoordinateSequence.h>
#include <geos/geom/CoordinateArraySequenceFactory.h>
// std
#include <memory>

namespace tut
{
    //
    // Test Group
    //

    // Common data used by tests
    struct test_segmentpointcomparator_data
    {

    	typedef std::auto_ptr<geos::geom::CoordinateSequence>
            CoordinateSequenceAutoPtr;

    	typedef std::auto_ptr<geos::noding::SegmentString>
            SegmentStringAutoPtr;
	
        const geos::geom::CoordinateSequenceFactory* csFactory;

        test_segmentpointcomparator_data()
            : csFactory(geos::geom::CoordinateArraySequenceFactory::instance())
	    {}
    };

    typedef test_group<test_segmentpointcomparator_data> group;
    typedef group::object object;

    group test_segmentpointcomparator_group("geos::noding::SegmentPointComparator");

    //
    // Test Cases
    //

    // TODO
    template<>
    template<>
    void object::test<1>()
    {

        // TODO - mloskot add test cases

    }

} // namespace tut
