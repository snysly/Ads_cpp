default: install

VPATH = scr:scr/obj:scr/InitialCondition:scr/GlobalFunctions:scr/Solvers:scr/NumericalRecipes

S_PATH     = ./scr/
IC_PATH    = ./scr/InitialCondition/
GF_PATH    = ./scr/GlobalFunctions/
SOLVER_PATH= ./scr/Solvers/
NUM_PATH   = ./scr/NumericalRecipes

F_OP = -Wall
CC   = g++
C_OP = -c
CEXE = main



SOLVER_CLASS    = SolverClass_RK4.o SolverClass_FirstOrder.o SolverClass_ForwardScheme.o

POTENTIAL_CLASS = FieldPotentialClass.h FieldPotentialClass_Massive_Scalar.o FieldPotentialClass_Higgs.o \
                  FieldPotentialClass_String.o

IC_CLASS  = InitialConditionClass_Gaussian.o

GLOB_FUNC = saveDataIntoFile.o solveTridiagonalMatrix.o

CLASSES_TEMP = ./InitialCondition/InitialConditionClass.h ./Solvers/TimeSolverClass.h \
               ./Solvers/SpatialSolverClass.h ./NumericalRecipes/Derivative.h

SIMP_HEADERS = ./NumericalRecipes/Derivative_ForwardScheme.h


OBJS = $(SIMP_HEADERS) $(CLASSES_TEMP) $(addprefix ./obj/, $(IC_CLASS) $(SOLVER_CLASS) $(GLOB_FUNC) FieldClass.o)

echo_PATH:
	echo $(PATH)

install:main.cpp $(IC_CLASS) $(SOLVER_CLASS) $(GLOB_FUNC) FieldClass.o
	echo  #
	echo  #
	echo  #
	echo  #
	cd $(S_PATH); \
	$(CC) $(F_OP) main.cpp $(OBJS) -o ../GravitationalCollapse

FieldClass.o:FieldClass.cpp FieldClass.h 
	cd $(S_PATH); \
	$(CC) $(C_OP) FieldClass.cpp -o ./obj/FieldClass.o 
	echo  FieldClass.o Created successfully

saveDataIntoFile.o:saveDataIntoFile.cpp \
                   saveDataIntoFile.h 
	cd $(GF_PATH); \
	$(CC) $(C_OP) saveDataIntoFile.cpp -o ../obj/saveDataIntoFile.o 
	echo  saveDataIntoFile.o Created successfully

solveTridiagonalMatrix.o:solveTridiagonalMatrix.cpp \
                         solveTridiagonalMatrix.h 
	cd $(GF_PATH); \
	$(CC) $(C_OP) solveTridiagonalMatrix.cpp -o ../obj/solveTridiagonalMatrix.o 
	echo  solveTridiagonalMatrix.o Created successfully

InitialConditionClass_Gaussian.o:InitialConditionClass_Gaussian.cpp \
                                 InitialConditionClass_Gaussian.h
	cd $(IC_PATH); \
	$(CC) $(C_OP) InitialConditionClass_Gaussian.cpp -o ../obj/InitialConditionClass_Gaussian.o 
	echo  InitialConditionClass_Gaussian.o Created successfully

SolverClass_RK4.o:SolverClass_RK4.cpp SolverClass_RK4.h
	cd $(SOLVER_PATH); \
	$(CC) $(C_OP) SolverClass_RK4.cpp -o ../obj/SolverClass_RK4.o 
	echo  SolverClass_RK4.o Created successfully

SolverClass_FirstOrder.o:SolverClass_FirstOrder.cpp SolverClass_FirstOrder.h
	cd $(SOLVER_PATH); \
	$(CC) $(C_OP) SolverClass_FirstOrder.cpp -o ../obj/SolverClass_FirstOrder.o 
	echo  SolverClass_FirstOrder.o Created successfully

SolverClass_ForwardScheme.o:SolverClass_ForwardScheme.cpp SolverClass_ForwardScheme.h
	cd $(SOLVER_PATH); \
	$(CC) $(C_OP) SolverClass_ForwardScheme.cpp -o ../obj/SolverClass_ForwardScheme.o 
	echo  SolverClass_ForwardScheme.o Created successfully

clean:
	/bin/rm -f $(CEXE) *mod *o *ocd GravitationalCollapse
	/bin/rm -f $(CEXE) ./scr/*mod ./scr/*o ./scr/*ocd
	/bin/rm -f $(CEXE) ./scr/*mod ./scr/obj/*o ./scr/obj/*ocd 
	/bin/rm -f ./output/snapshots/*txt


CSRC= helloworld.cpp
REST= readme run makefile helloworld.c

tar:
	-tar -czvf ../xxx.tar.gz ../xxx
	
