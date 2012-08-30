/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author edemairy
 */
public class PointTest {
    
    public PointTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of draw method, of class Point.
     */
    @Test
    public void testDraw() {
        System.out.println("draw");
        Point instance = null;
        instance.draw();
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of drawTo method, of class Point.
     */
    @Test
    public void testDrawTo() {
        System.out.println("drawTo");
        Point that = null;
        Point instance = null;
        instance.drawTo(that);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of slopeTo method, of class Point.
     */
    @Test
    public void testSlopeTo() {
        System.out.println("slopeTo");
        Point that = null;
        Point instance = null;
        double expResult = 0.0;
        double result = instance.slopeTo(that);
        assertEquals(expResult, result, 0.0);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of compareTo method, of class Point.
     */
    @Test
    public void testCompareTo() {
        Point p1 = new Point(1,1);
        Point p2 = new Point(1,2);
        Point p3 = new Point(2,2);
        Point p4 = new Point(2,1);
        assertTrue(p1.compareTo(p2) < 0);
        assertTrue(p1.compareTo(p4) < 0);
        assertTrue(p1.compareTo(p1) == 0);
        assertTrue(p3.compareTo(p4) > 0);
        assertTrue(p3.compareTo(p2) > 0);        
    }

    /**
     * Test of toString method, of class Point.
     */
    @Test
    public void testToString() {
        System.out.println("toString");
        Point instance = null;
        String expResult = "";
        String result = instance.toString();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of main method, of class Point.
     */
    @Test
    public void testMain() {
        System.out.println("main");
        String[] args = null;
        Point.main(args);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }
}
