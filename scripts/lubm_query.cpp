#include "../Database/Database.h"
#include "../Util/Util.h"
#include <iostream>

using namespace std;


int main(int argc, char * argv[])
{
    Util util;

    if(argc < 2){
        cout << "no database name!" << endl;
        return 0;
    }

    string db_folder = argv[1];

    Database _db(db_folder);
    _db.load();
    cout << "finish load!" << endl;
    string q[21];
    q[0] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?x where\
    {\
    ?x	rdf:type	ub:GraduateStudent.\
    ?y	rdf:type	ub:University.\
    ?z	rdf:type	ub:Department.\
    ?x	ub:memberOf	?z.\
    ?z	ub:subOrganizationOf	?y.\
    ?x	ub:undergraduateDegreeFrom	?y.\
    }\
    ";
    q[1] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?x where\
    {\
    ?x	rdf:type	ub:Course.\
    ?x	ub:name	?y.\
    }\
    ";

    q[2] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?x where\
    {\
    ?x	rdf:type	ub:UndergraduateStudent.\
    ?y	rdf:type	ub:University.\
    ?z	rdf:type	ub:Department.\
    ?x	ub:memberOf	?z.\
    ?z	ub:subOrganizationOf	?y.\
    ?x 	ub:undergraduateDegreeFrom	?y.\
    }\
    ";

    q[3] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?x ?y1 ?y2 ?y3 where\
    {\
    ?x	ub:worksFor	<http://www.Department0.University0.edu>.\
    ?x	rdf:type	ub:FullProfessor.\
    ?x	ub:name	?y1.\
    ?x	ub:emailAddress	?y2.\
    ?x	ub:telephone	?y3.\
    }\
    ";

    q[4] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?x where\
    {\
    ?x	ub:subOrganizationOf	<http://www.Department0.University0.edu>.\
    ?x	rdf:type	ub:ResearchGroup.\
    }\
    ";

    q[5] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?x ?y where\
    {\
    ?y	ub:subOrganizationOf	<http://www.University0.edu>.	\
    ?y	rdf:type	ub:Department.\
    ?x	ub:worksFor	?y.\
    ?x	rdf:type	ub:FullProfessor.\
    }\
    ";

    q[6] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?x ?y ?z where\
    {\
    ?x	rdf:type	ub:UndergraduateStudent.\
    ?y	rdf:type	ub:FullProfessor.\
    ?z	rdf:type	ub:Course.\
    ?x	ub:advisor	?y.\
    ?x	ub:takesCourse	?z.\
    ?y	ub:teacherOf	?z.\
    }\
    ";

    q[7] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X where\
    {\
    ?X	rdf:type	ub:GraduateStudent.\
    ?X	ub:takesCourse	<http://www.Department0.University0.edu/GraduateCourse0>.\
    }\
    ";

    q[8] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X ?Y ?Z where\
    {\
    ?X	rdf:type	ub:GraduateStudent.\
    ?Y	rdf:type	ub:University.\
    ?Z	rdf:type	ub:Department.\
    ?X	ub:memberOf	?Z.\
    ?Z	ub:subOrganizationOf	?Y.\
    ?X	ub:undergraduateDegreeFrom	?Y.\
    }\
    ";

    q[9] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X where\
    {\
    ?X	rdf:type	ub:Publication.\
    ?X	ub:publicationAuthor	<http://www.Department0.University0.edu/AssistantProfessor0>.\
    }\
    ";

    q[10] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?Y1 ?Y2 ?Y3 where\
    {\
    ?X	rdf:type	ub:FullProfessor.\
    ?X	ub:worksFor	<http://www.Department0.University0.edu>.\
    ?X	ub:name	?Y1.\
    ?X	ub:emailAddress	?Y2.\
    ?X	ub:telephone	?Y3.\
    }\
    ";

    q[11] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X where\
    {\
    ?X	ub:memberOf	<http://www.Department0.University0.edu>.	\
    }\
    ";

    q[12] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X where\
    {\
    ?X	rdf:type	ub:UndergraduateStudent.\
    }\
    ";
    
    q[13] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X ?Y where\
    {\
    ?X	rdf:type	ub:Student.\
    ?Y	rdf:type	ub:Course.\
    ?X	ub:takesCourse	?Y.\
    <http://www.Department0.University0.edu/AssociateProfessor0>	ub:teacherOf	?Y.\
    }\
    ";

    q[14] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X where\
    {\
    ?X	rdf:type	ub:UndergraduateStudent.\
    ?Y	rdf:type	ub:Department.\
    ?X	ub:memberOf	?Y.\
    ?Y	ub:subOrganizationOf	<http://www.University0.edu>.\
    ?X	ub:emailAddress	?Z.\
    }\
    ";

    q[15] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X ?Y ?Z where\
    {\
    ?X	rdf:type	ub:UndergraduateStudent.\
    ?Z	rdf:type	ub:Course.\
    ?X	ub:advisor	?Y.\
    ?Y	ub:teacherOf	?Z.\
    ?X	ub:takesCourse	?Z.\
    }\
    ";

    q[16] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X where\
    {\
    ?X	rdf:type	ub:GraduateStudent.\
    ?X	ub:takesCourse	<http://www.Department0.University0.edu/GraduateCourse0>.\
    }\
    ";

    q[17] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X where\
    {\
    ?X	rdf:type	ub:ResearchGroup.\
    ?X	ub:subOrganizationOf	<http://www.University0.edu>.\
    }\
    ";

    q[18] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X ?Y where\
    {\
    ?Y	rdf:type	ub:Department.\
    ?X	ub:worksFor	?Y.\
    ?Y	ub:subOrganizationOf	<http://www.University0.edu>.\
    }\
    ";

    q[19] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X where\
    {\
    <http://www.University0.edu>	ub:undergraduateDegreeFrom	?X.\
    }\
    ";

    q[20] = "\
    PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\
    PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>\
    select ?X where\
    {\
    ?X	rdf:type	ub:UndergraduateStudent.\
    }\
    ";
    ResultSet rs;
    FILE *_fp = fopen("./lubm_res.txt", "a");
    for(int i = 0; i < 21; i++)
    {
        _db.query(q[i], rs, _fp);
    }
    fclose(_fp);
    return 0;
}