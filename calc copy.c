/*
 * CALC -- program to implement a simple arithmetic calculator
 *
 * Usage: calc
 *
 * Inputs (from standard input)
 *      -- operator, one of + - * / %
 *      -- 2 operands, both integers
 *
 * Exit Code: 0 if all is well, 1 on error
 *
 * written for ECS 030, Fall 2015
 * 
 * Matt Bishop, Sept. 24, 2015
 *      original program written
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * MACROS
 *
 * These are to encode the operations
 */
#define	ERROR		0		/* unknown operation */
#define	ADD			1		/* addition operation */
#define	SUBTRACT	2		/* subtraction operation */
#define	MULTIPLY	3		/* multiplication operation */
#define	DIVIDE		4		/* division operation */
#define	REMAINDER	5		/* modulus operation */


/*
 * GETOP -- get an integer operand; we do operation-specific checks later
 *
 * parameters: opno	the number of the operand (as in 1st, 2nd, etc.)
 * returns: int		the integer value of the operand just read
 * exceptions: none
 */
int getop(int opno)
{
	int val;		/* value read */
	int rv;			/* value returned from scanf */

	/*
 	 * loop until you get an integer or EOF
 	 */
	do{
		/* prompt and read a value, prints error message if bogus value */
		printf("\toperand %d: ", opno);
		/*change made; put rv=scanf inside the if statement*/
		if ((rv = scanf("%d", &val))==0){
		printf("\toperand must be an integer\n");
		}
		/* loop until a valid value */
	} while (rv == 0);

	/*
 	 * if it's EOF, say so and quit
 	 */
	if (rv == EOF)
		exit(EXIT_SUCCESS);

	/*
 	 * otherwise, say what you read
 	 */
	return(val);
}

/*
 * VALOP -- return value of operation
 *
 * parameters: int	a character representing the operator
 * returns: int		operator code (see above) or ERROR 
 * exceptions: none
 */
/*changed to char*/
int valop(char op)
{
	/*added breaks*/
	switch(op){		/* map character into code */
	case '+':    return(ADD);
				break;
	case '-':    return(SUBTRACT);
				break;
	case '*':    return(MULTIPLY);
				break;
	case '/':    return(DIVIDE);
				break;
	case '%':    return(REMAINDER);
				break;
	

	/*
	 * unknown character -- balk
	 */
	default:
		return (ERROR);
		break;
	}
}

/*
 * ISDIVOP -- return 1 if argument is a division operator
 *
 * parameters: int	a character representing the operator
 * returns: int		1 if argument is '/' or '%', 0 otherwise
 * exceptions: none
 */
int isdivop(int op)
{
	return(op == DIVIDE || op == REMAINDER);
}

/*
 * APPLY -- perform desired calculation
 *
 * parameters: int	first operand
 *             int	second operand
 *             int	operation
 *             ***** assume: if operation is a division one, the
 *             ***** second operand is non-zero
 * returns: int		result
 * exceptions: none
 */
int apply(int op1, int op, int op2)
{
	int answer;			/* the answer */

	/*
	 * do the operation or complain
	 */
	switch(op){
	case ADD:		/* add them */
		answer= op1 + op2;
		break;
	case SUBTRACT:		/* subtract second from first */
		 answer= op1 - op2;
		break;
	case MULTIPLY:		/* multiply them */
		answer= op1 * op2;
		break;
	case DIVIDE:		/* divide first by second */
		answer= op1 / op2;
		break;
	case REMAINDER:		/* remainder when first divided by second */
		answer= op1 % op2;
		break;
	default:		/* should never happen ... */
		printf("Internal inconsistency: bad operator %d in apply\n", op);
		exit(EXIT_FAILURE);
	}

	/*
	 * now return the answer
	 */
	return(answer);
}
		

int main(void)
{
	char ch;			/* input character */
	int op;			/* operation, derived from ch */
	int op1, op2;		/* operands */
	int result;		/* result to be printed */


	/*
	 * prompt the user for an operation
	 */
	printf("operation (+,-,*,/,%%)> ");

	/*
	 * loop until user says to quit
	 */
	while((ch = getchar()) != EOF){
		/* convert the character read to an operator */
		/*change made: now checks if valop(ch) itself returns an error, not if assigning valop(ch) to ch returns error*/
		/*change made: made the while loop only include the if statment*/
		/*change made: removed continue statement at end of while loop*/
		/* WHY IS IT PRINTING THIS */
		/*
		if (valop(ch) == ERROR){
			fprintf(stderr, "invalid operator %c\n", ch);
			printf("operation (+,-,*,/,%%)> ");
		} */
	}
	
		/* get the operands */
		op = valop(ch);
		op1 = getop(1);
		op2 = getop(2);
		/*
		 * if division operation by 0, complain
		 * otherwise do the operation
		 */
		if (isdivop(op) && op2 == 0)
			fprintf(stderr, "Can't have a denominator of 0\n");
		else{
			result = apply(op1, op, op2);
			printf("\t%d %c %d = %d\n", op1, ch, op2, result);
		}
		/* prompt again */
		printf("operation (+,-,*,/,%%)> ");
	
	/*
	 * make it look nice
	 */
	putchar('\n');

	/*
	 * that's all, folks!
	 */
	return(EXIT_SUCCESS);
}
