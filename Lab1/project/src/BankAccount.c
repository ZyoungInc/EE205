#include "BankAccount.h"

struct BankAccount {
    double balance;
    double last_withdrawl;
    double last_deposit;
};

/*
 * Implement the definitions for the
 * functions involving BankAccount from BankAccount.h here,
 *
 * Make sure to produce comments that look like this!
 * (Try to copy the formatting.)
 *
 * For BankAccount_construct() and BankAccount_destroy(),
 * if you do not remember malloc() and free(), review them
 * by creating a toy program.
 */


/*
 * Allocates a new BankAccount with a set balance.
 */
BankAccount* BankAccount_construct(double balance) {
    struct BankAccount *BankACC = malloc(sizeof(struct BankAccount));
    BankACC->balance = balance;
	BankACC->last_withdrawl = 0.0;
	BankACC->last_deposit = 0.0;
	return BankACC;
}

/*
 * Destroys a BankAccount by freeing its memory.
 */
void BankAccount_destroy(BankAccount* ba){
    free(ba);
}

/*
 * Performs a deposit on an account.
 *
 * - Bonus feature: checking for overflow/underflow.
 *   - Does not modify ba->balance on error.
 *
 * Returns: 0 on success, 1 on overflow, -1 on underflow.
 */
int BankAccount_deposit(BankAccount* ba, double amount) {
	double max_change = 0;
	
	if (ba->balance >= 0) {
		//check for maximum allowed change for a double
		// only if your balance is above 0
		max_change = DBL_MAX - ba->balance;
	}
	else {
		// else you can deposit the max value for a double if you're in the negative
		max_change = DBL_MAX;
	}
	
	if (amount <= 0) {
		//Cannot deposit a negative number
		return -1;
	}
	else if (max_change <= amount){
		//Over flow detection
		return 1;
	}
	else {
		ba->balance += amount;
		ba->last_deposit = amount;
		return 0;
	}
	
}
/*
 * Performs a withdrawal on a BankAccount.
 * 
 */
int BankAccount_withdraw(BankAccount* ba, double amount){
	double max_change;
	
	if (ba->balance < 0) {
	
		//check for maximum allowed change for a double
		// only if your balance is under 0
		max_change = DBL_MAX + ba->balance;
	}
	else {
		max_change = DBL_MAX;
	}
	
	if (amount <= 0) {
			//Cannot withdraw a negative number
			return -1;
	}
	else if (max_change <= amount) {
			//Cannot withdraw more money then you own
			return 1;
	}
	else {
			ba->balance -= amount;
			ba->last_deposit = amount;
			return 0;
	}

}

/*
 * Gets the balance for a BankAccount.
 */
double BankAccount_get_balance(BankAccount* ba){
	return ba->balance;
}

/*
 * Gets the last deposit amount for a BankAccount.
 */
double BankAccount_get_last_deposit(BankAccount* ba){
	return ba->last_deposit;
}
/*
 * Gets the last withdrawl amount for a BankAccount.
 */
double BankAccount_get_last_withdrawal(BankAccount* ba) {
	return ba->last_withdrawl;
}
