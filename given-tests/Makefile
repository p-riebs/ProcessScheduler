#
# Josh Hursey
# CS 441/541: Project 4 Given Tests
#

check: scheduler banner_help \
	check-level-1 check-level-2 check-level-3 \
	check-level-4 check-level-5 check-level-6 \
	check-level-7

banner_help:
	@echo "By default check will run all levels."
	@echo "You can run an individual level by using one of the following:"
	@echo "   check-level-1"
	@echo "   check-level-2"
	@echo "   check-level-3"
	@echo "   check-level-4"
	@echo "   check-level-5"
	@echo "   check-level-6"
	@echo "   check-level-7"
	@echo ""
	@sleep 1

###############################################
# Tests - Level 1
###############################################
LEVEL_1_INPUT=given-tests/level1.txt
check-level-1: scheduler banner_1 \
	check-level-1-s-1 check-level-1-s-2 check-level-1-s-3 \
	check-level-1-s-4-q-2 check-level-1-s-4-q-5 check-level-1-s-4-q-10

banner_1:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 1 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"

LEVEL_1_EXP_S_1=given-tests/level1-exp-s-1.txt
check-level-1-s-1: scheduler
	@given-tests/check.pl 1 0 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_S_1)

LEVEL_1_EXP_S_2=given-tests/level1-exp-s-2.txt
check-level-1-s-2: scheduler
	@given-tests/check.pl 2 0 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_S_2)

LEVEL_1_EXP_S_3=given-tests/level1-exp-s-3.txt
check-level-1-s-3: scheduler
	@given-tests/check.pl 3 0 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_S_3)

LEVEL_1_EXP_S_4_Q_2=given-tests/level1-exp-s-4-q-2.txt
check-level-1-s-4-q-2: scheduler
	@given-tests/check.pl 4 2 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_S_4_Q_2)

LEVEL_1_EXP_S_4_Q_5=given-tests/level1-exp-s-4-q-5.txt
check-level-1-s-4-q-5: scheduler
	@given-tests/check.pl 4 5 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_S_4_Q_5)

LEVEL_1_EXP_S_4_Q_10=given-tests/level1-exp-s-4-q-10.txt
check-level-1-s-4-q-10: scheduler
	@given-tests/check.pl 4 10 $(LEVEL_1_INPUT) $(LEVEL_1_EXP_S_4_Q_10)

###############################################
# Tests - Level 2
###############################################
LEVEL_2_INPUT=given-tests/level2.txt
check-level-2: scheduler banner_2 \
	check-level-2-s-1 check-level-2-s-2 check-level-2-s-3 \
	check-level-2-s-4-q-2 check-level-2-s-4-q-5 check-level-2-s-4-q-10

banner_2:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 2 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@sleep 1

LEVEL_2_EXP_S_1=given-tests/level2-exp-s-1.txt
check-level-2-s-1: scheduler
	@given-tests/check.pl 1 0 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_S_1)

LEVEL_2_EXP_S_2=given-tests/level2-exp-s-2.txt
check-level-2-s-2: scheduler
	@given-tests/check.pl 2 0 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_S_2)

LEVEL_2_EXP_S_3=given-tests/level2-exp-s-3.txt
check-level-2-s-3: scheduler
	@given-tests/check.pl 3 0 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_S_3)

LEVEL_2_EXP_S_4_Q_2=given-tests/level2-exp-s-4-q-2.txt
check-level-2-s-4-q-2: scheduler
	@given-tests/check.pl 4 2 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_S_4_Q_2)

LEVEL_2_EXP_S_4_Q_5=given-tests/level2-exp-s-4-q-5.txt
check-level-2-s-4-q-5: scheduler
	@given-tests/check.pl 4 5 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_S_4_Q_5)

LEVEL_2_EXP_S_4_Q_10=given-tests/level2-exp-s-4-q-10.txt
check-level-2-s-4-q-10: scheduler
	@given-tests/check.pl 4 10 $(LEVEL_2_INPUT) $(LEVEL_2_EXP_S_4_Q_10)

###############################################
# Tests - Level 3
###############################################
LEVEL_3_INPUT=given-tests/level3.txt
check-level-3: scheduler banner_3 \
	check-level-3-s-1 check-level-3-s-2 check-level-3-s-3 \
	check-level-3-s-4-q-2 check-level-3-s-4-q-5 check-level-3-s-4-q-10

banner_3:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 3 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@sleep 1

LEVEL_3_EXP_S_1=given-tests/level3-exp-s-1.txt
check-level-3-s-1: scheduler
	@given-tests/check.pl 1 0 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_S_1)

LEVEL_3_EXP_S_2=given-tests/level3-exp-s-2.txt
check-level-3-s-2: scheduler
	@given-tests/check.pl 2 0 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_S_2)

LEVEL_3_EXP_S_3=given-tests/level3-exp-s-3.txt
check-level-3-s-3: scheduler
	@given-tests/check.pl 3 0 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_S_3)

LEVEL_3_EXP_S_4_Q_2=given-tests/level3-exp-s-4-q-2.txt
check-level-3-s-4-q-2: scheduler
	@given-tests/check.pl 4 2 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_S_4_Q_2)

LEVEL_3_EXP_S_4_Q_5=given-tests/level3-exp-s-4-q-5.txt
check-level-3-s-4-q-5: scheduler
	@given-tests/check.pl 4 5 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_S_4_Q_5)

LEVEL_3_EXP_S_4_Q_10=given-tests/level3-exp-s-4-q-10.txt
check-level-3-s-4-q-10: scheduler
	@given-tests/check.pl 4 10 $(LEVEL_3_INPUT) $(LEVEL_3_EXP_S_4_Q_10)


###############################################
# Tests - Level 4
###############################################
LEVEL_4_INPUT=given-tests/level4.txt
check-level-4: scheduler banner_4 \
	check-level-4-s-1 check-level-4-s-2 check-level-4-s-3 \
	check-level-4-s-4-q-2 check-level-4-s-4-q-5 check-level-4-s-4-q-10

banner_4:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 4 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@sleep 1

LEVEL_4_EXP_S_1=given-tests/level4-exp-s-1.txt
check-level-4-s-1: scheduler
	@given-tests/check.pl 1 0 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_S_1)

LEVEL_4_EXP_S_2=given-tests/level4-exp-s-2.txt
check-level-4-s-2: scheduler
	@given-tests/check.pl 2 0 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_S_2)

LEVEL_4_EXP_S_3=given-tests/level4-exp-s-3.txt
check-level-4-s-3: scheduler
	@given-tests/check.pl 3 0 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_S_3)

LEVEL_4_EXP_S_4_Q_2=given-tests/level4-exp-s-4-q-2.txt
check-level-4-s-4-q-2: scheduler
	@given-tests/check.pl 4 2 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_S_4_Q_2)

LEVEL_4_EXP_S_4_Q_5=given-tests/level4-exp-s-4-q-5.txt
check-level-4-s-4-q-5: scheduler
	@given-tests/check.pl 4 5 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_S_4_Q_5)

LEVEL_4_EXP_S_4_Q_10=given-tests/level4-exp-s-4-q-10.txt
check-level-4-s-4-q-10: scheduler
	@given-tests/check.pl 4 10 $(LEVEL_4_INPUT) $(LEVEL_4_EXP_S_4_Q_10)


###############################################
# Tests - Level 5
###############################################
LEVEL_5_INPUT=given-tests/level5.txt
check-level-5: scheduler banner_5 \
	check-level-5-s-1 check-level-5-s-2 check-level-5-s-3 \
	check-level-5-s-4-q-2 check-level-5-s-4-q-5 check-level-5-s-4-q-10

banner_5:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 5 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@sleep 1

LEVEL_5_EXP_S_1=given-tests/level5-exp-s-1.txt
check-level-5-s-1: scheduler
	@given-tests/check.pl 1 0 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_S_1)

LEVEL_5_EXP_S_2=given-tests/level5-exp-s-2.txt
check-level-5-s-2: scheduler
	@given-tests/check.pl 2 0 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_S_2)

LEVEL_5_EXP_S_3=given-tests/level5-exp-s-3.txt
check-level-5-s-3: scheduler
	@given-tests/check.pl 3 0 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_S_3)

LEVEL_5_EXP_S_4_Q_2=given-tests/level5-exp-s-4-q-2.txt
check-level-5-s-4-q-2: scheduler
	@given-tests/check.pl 4 2 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_S_4_Q_2)

LEVEL_5_EXP_S_4_Q_5=given-tests/level5-exp-s-4-q-5.txt
check-level-5-s-4-q-5: scheduler
	@given-tests/check.pl 4 5 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_S_4_Q_5)

LEVEL_5_EXP_S_4_Q_10=given-tests/level5-exp-s-4-q-10.txt
check-level-5-s-4-q-10: scheduler
	@given-tests/check.pl 4 10 $(LEVEL_5_INPUT) $(LEVEL_5_EXP_S_4_Q_10)


###############################################
# Tests - Level 6
###############################################
LEVEL_6_INPUT=given-tests/level6.txt
check-level-6: scheduler banner_6 \
	check-level-6-s-1 check-level-6-s-2 check-level-6-s-3 \
	check-level-6-s-4-q-2 check-level-6-s-4-q-5 check-level-6-s-4-q-10

banner_6:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 6 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@sleep 1

LEVEL_6_EXP_S_1=given-tests/level6-exp-s-1.txt
check-level-6-s-1: scheduler
	@given-tests/check.pl 1 0 $(LEVEL_6_INPUT) $(LEVEL_6_EXP_S_1)

LEVEL_6_EXP_S_2=given-tests/level6-exp-s-2.txt
check-level-6-s-2: scheduler
	@given-tests/check.pl 2 0 $(LEVEL_6_INPUT) $(LEVEL_6_EXP_S_2)

LEVEL_6_EXP_S_3=given-tests/level6-exp-s-3.txt
check-level-6-s-3: scheduler
	@given-tests/check.pl 3 0 $(LEVEL_6_INPUT) $(LEVEL_6_EXP_S_3)

LEVEL_6_EXP_S_4_Q_2=given-tests/level6-exp-s-4-q-2.txt
check-level-6-s-4-q-2: scheduler
	@given-tests/check.pl 4 2 $(LEVEL_6_INPUT) $(LEVEL_6_EXP_S_4_Q_2)

LEVEL_6_EXP_S_4_Q_5=given-tests/level6-exp-s-4-q-5.txt
check-level-6-s-4-q-5: scheduler
	@given-tests/check.pl 4 5 $(LEVEL_6_INPUT) $(LEVEL_6_EXP_S_4_Q_5)

LEVEL_6_EXP_S_4_Q_10=given-tests/level6-exp-s-4-q-10.txt
check-level-6-s-4-q-10: scheduler
	@given-tests/check.pl 4 10 $(LEVEL_6_INPUT) $(LEVEL_6_EXP_S_4_Q_10)


###############################################
# Tests - Level 7
###############################################
LEVEL_7_INPUT=given-tests/level7.txt
check-level-7: scheduler banner_7 \
	check-level-7-s-1 check-level-7-s-2 check-level-7-s-3 \
	check-level-7-s-4-q-2 check-level-7-s-4-q-5 check-level-7-s-4-q-10

banner_7:
	@echo ""
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@echo "mmmmmmmmm Level 7 Tests mmmmmmmmmmm"
	@echo "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
	@sleep 1

LEVEL_7_EXP_S_1=given-tests/level7-exp-s-1.txt
check-level-7-s-1: scheduler
	@given-tests/check.pl 1 0 $(LEVEL_7_INPUT) $(LEVEL_7_EXP_S_1)

LEVEL_7_EXP_S_2=given-tests/level7-exp-s-2.txt
check-level-7-s-2: scheduler
	@given-tests/check.pl 2 0 $(LEVEL_7_INPUT) $(LEVEL_7_EXP_S_2)

LEVEL_7_EXP_S_3=given-tests/level7-exp-s-3.txt
check-level-7-s-3: scheduler
	@given-tests/check.pl 3 0 $(LEVEL_7_INPUT) $(LEVEL_7_EXP_S_3)

LEVEL_7_EXP_S_4_Q_2=given-tests/level7-exp-s-4-q-2.txt
check-level-7-s-4-q-2: scheduler
	@given-tests/check.pl 4 2 $(LEVEL_7_INPUT) $(LEVEL_7_EXP_S_4_Q_2)

LEVEL_7_EXP_S_4_Q_5=given-tests/level7-exp-s-4-q-5.txt
check-level-7-s-4-q-5: scheduler
	@given-tests/check.pl 4 5 $(LEVEL_7_INPUT) $(LEVEL_7_EXP_S_4_Q_5)

LEVEL_7_EXP_S_4_Q_10=given-tests/level7-exp-s-4-q-10.txt
check-level-7-s-4-q-10: scheduler
	@given-tests/check.pl 4 10 $(LEVEL_7_INPUT) $(LEVEL_7_EXP_S_4_Q_10)
