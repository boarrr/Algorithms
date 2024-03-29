/*
  Description: Algorithms Assignment, a data structure for a pharmaceutical manufacturing companies line logs, 
    including functions to generate reports and search for data with specific time complexity constraints
  Author: Ryan Pitman
  Date: 29/04/2024
*/

#include <stdio.h>
#include <stdlib.h>

#define LOG_SIZE 6
#define LINE_COUNT 4
#define TOTAL_LOGS (LOG_SIZE * LINE_COUNT)

typedef struct date 
{
  int day;
  int hour;
  int minute;
} date;

typedef struct issue
{
  int issue_code;
  char issue_description[100];
} issue;

typedef struct resolution 
{
  int resolution_code;
  char resolution_description[100];
} resolution;


typedef struct product_line_key
{
	int product_id;
	int line_id;
} product_line_key;

typedef struct issue_node
{
	int issue_id;
	struct issue_node* next;
} issue_node;

typedef struct product_line 
{
  int line_code;
  int batch_code;
  date batch_date;
  int product_id;
	issue issue_info;
	resolution resolution_info;
	int reporting_employee;
} product_line;

typedef struct merged_issues
{
	int product_id;
	int line_code;
	int issue_id;
} merged_issues;

typedef struct product_summary
{
	int product_id;
	int issue_count;
}	product_summary;

void insert_test_data(product_line**);
void report_on_productid(product_line**, int, int);
void merge_sort(product_line*, int, int);
void merge(product_line*, int, int, int);
int compare_lines(product_line* line1, product_line* line2);
merged_issues* report_on_issues(product_line**, int, int, int*);
void search_by_issue(merged_issues*, int);
void summarize_products(merged_issues*, int);


int main(void) 
{
	product_line line1_log[LOG_SIZE], line2_log[LOG_SIZE], line3_log[LOG_SIZE], line4_log[LOG_SIZE];
	product_line *line_array[LINE_COUNT] = {line1_log, line2_log, line3_log, line4_log};
	merged_issues *issue_report;
	int total_issues;

	insert_test_data(line_array);

	printf("\n---TASK 1) Report based on product ID---\n");
	report_on_productid(line_array, LINE_COUNT, LOG_SIZE);

	printf("\n---TASK 2) Issues Report---\n\n");
	issue_report = report_on_issues(line_array, LINE_COUNT, LOG_SIZE, &total_issues);

	printf("\n---TASK 3) Search by product ID---\n\n");
	search_by_issue(issue_report, total_issues);

	printf("\n---TASK 4) Summary report of issues counts---\n\n");
	summarize_products(issue_report, total_issues);

	free(issue_report);
	
	return 0;
}


/* Task 1) Generate a report sorted by product id, issue code, and then date and time */


// Reporting function, prints the result of the merge
void report_on_productid(product_line** line_array, int lines, int log_size)
{
	for (int i = 0; i < lines; i++) 
	{
		// Sort the current line's logs by product ID using merge sort
		merge_sort(line_array[i], 0, log_size - 1);

		// Print the sorted logs
		printf("\n---Sorted Logs for Line %d---\n", i + 1);
		
		for (int j = 0; j < log_size; j++) 
		{
			// Create a temporary instance of the product_line struct for ease of printing
			product_line log = line_array[i][j];
			
			printf("Product ID: %d, Issue Code: %d, Date: %02d-%02d-%02d\n", log.product_id, log.issue_info.issue_code,
			log.batch_date.day, log.batch_date.hour, log.batch_date.minute);
		}
	}
}


// Merge part of the mergesort function, sorting based on product id
void merge(product_line* arr, int low, int mid, int high)
{
	int left_size = mid - low + 1;
	int right_size = high - mid;

	product_line left_arr[left_size], right_arr[right_size];

	// Copy left data into temporary array
	for(int i = 0; i < left_size; i++) left_arr[i] = arr[low + i];

	// Copy right data into a temporary array
	for(int i = 0; i < right_size; i++) right_arr[i] = arr[mid + 1 + i];

	// Left and right pointers, index for the merged array
	int left = 0, right = 0, index = low;

	// Merge the two arrays based on product_id.
	while(left < left_size && right < right_size)
	{
		// If the function returns a negative number, the left value is smaller comparitively
		if (compare_lines(&left_arr[left], &right_arr[right]) <= 0) arr[index++] = left_arr[left++];
			
		// Else, the right is the smaller value, so take that
		else arr[index++] = right_arr[right++];
	}

	// Assign any left over variables
	while(left < left_size) arr[index++] = left_arr[left++];
	while(right < right_size) arr[index++] = right_arr[right++];
}


// Merge sort function
void merge_sort(product_line* array, int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;
		merge_sort(array, low, mid);
		merge_sort(array, mid + 1, high);
		merge(array, low, mid, high);
	}
}


/* 
// Compare between two log lines for sorting
// Prioritize by product id first, then issue code, and finally date.
// Returns a negative number if the first line is smaller, a positive number if the second line is smaller, and 0 if they are equal
*/
int compare_lines(product_line* line1, product_line* line2)
{
	// Compare by product ID, if they're not equal, return the difference
	if (line1->product_id != line2->product_id) return line1->product_id - line2->product_id;

	// If product ID is equal, compare by issue code, and return the difference
	if (line1->issue_info.issue_code != line2->issue_info.issue_code) return line1->issue_info.issue_code - line2->issue_info.issue_code;

	// If issue code and product id are also equal, compare by date and retun the difference
	if (line1->batch_date.day != line2->batch_date.day) return line1->batch_date.day - line2->batch_date.day;

	// Both entries are completely equal, return 0
	return 0; 
}



/* Task 2) Prepare a report based on Issue Code and Product ID */


// Reporting function, merges all four lines into a single array sorted by product ID
// Due to task 1), the data is in perfect order for this operation
// Then reports based on product id
merged_issues* report_on_issues(product_line** line_array, int lines, int log_size, int* total_issues)
{
	// Create an array to store all the merged issues instances, dynamically to ensure we can return that memory to main
	merged_issues* merged = malloc(TOTAL_LOGS * sizeof(merged_issues));

	// If memory allocation fails
	if (!merged)
	{	
		*total_issues = 0;
		return NULL;
	}

	// Assign an index of 0 for each inputted line into the merge, 
	// In this case 4 lines are being merged into one array
	// Contrary to how merge normally tracks 2 indexes
	int log_indexes[LINE_COUNT] = {0};
	int index = 0;

	// While there is still data to be merged
	while (index < TOTAL_LOGS)
	{
		int min_index = -1;
		product_line* min_log = NULL;

		// Find the minimum log in the array
		for (int i = 0; i < LINE_COUNT; i++)
		{
			// If the current log has more data to process
			if(log_indexes[i] < log_size)
			{
				// Assign the current log to the current log in this line
				product_line* current_log = &line_array[i][log_indexes[i]];

				// Reuse the comparison function from Task 1
				if(!min_log || compare_lines(current_log, min_log) < 0)
				{
					min_log = current_log;
					min_index = i;
				}
			}

			// Next, add the found min log to the merged array
			if(min_log)
			{
				merged[index++] = (merged_issues) 
				{
					.product_id = min_log->product_id, 
					.line_code = min_log->line_code, 
					.issue_id = min_log->issue_info.issue_code
				};

				// Iterate the line log that we took the min from
				log_indexes[min_index]++; 
			}
		}
	}

	// Merged array should now correctly contain all the issues, sorted by product id, 
	// Display the report
	for (int i = 0; i < TOTAL_LOGS; i++) printf("Product ID: %d, Line Code: %d, Issue Code: %d\n", merged[i].product_id, merged[i].line_code, merged[i].issue_id);

	// The count of issues is how many iterations of index happened
	*total_issues = index;
	return merged;
}


/* Task 3) Search for the earliest occurence of an issue code for a given product ID across all lines */

// Search function, searches for the earliest occurence of an issue code for a given product ID across, using binary search algorithm for O(LogN) time complexity
void search_by_issue(merged_issues* arr, int total_issues) 
{
	int low = 0, high = total_issues - 1;
	int user_product_id;
	int result_index = -1; // Store the index of the found issue
	
	printf("Enter a product ID to search for: ");
	scanf("%d", &user_product_id);

	// While the low index is not over high, then there are divisions to happen
	while (low <= high) 
	{
		int mid = low + (high - low) / 2;

		if (arr[mid].product_id == user_product_id) 
		{
			// Update result index to current match
			result_index = mid; 
			// Move left to find the earliest occurrence for the product id
			high = mid - 1; 
		}
		// If the mid is greater than the user product id, then move left
		else if (arr[mid].product_id < user_product_id) low = mid + 1;
		// Else, move right
		else high = mid - 1;
		
	}

	// If result index is not the default, that product id was found
	if (result_index != -1) printf("Earliest Occurrence - Product ID: %d, Line Code: %d, Issue Code: %d\n", arr[result_index].product_id, arr[result_index].line_code, arr[result_index].issue_id);
 	else printf("No product ID found.\n");
}


/* Task 4) Prepare a summary report of all products, and their issue counts */

// O(N) report function, iterates through all merged products and counts unique products
// Then counts the issues for each unique product
void summarize_products(merged_issues* merged_arr, int issue_count) 
{
	if (issue_count == 0) return;

	// Initialize summary for the first product
	product_summary summaries[TOTAL_LOGS]; 
	
	int summary_index = 0;

	// Assign the first product to the summary
	summaries[0].product_id = merged_arr[0].product_id;
	summaries[0].issue_count = 1;

	for (int i = 1; i < issue_count; i++) 
	{
		// If it is a unique product, store it in the next slot in the summary array
		if (merged_arr[i].product_id != merged_arr[i-1].product_id) 
		{
			// Move to the next summary entry for a new product
			summary_index++;

			// Assign the new product to the summary
			summaries[summary_index].product_id = merged_arr[i].product_id;
			summaries[summary_index].issue_count = 1;
		} 
		// Otherwise, it already exists, iterate the issue count for that product
		else summaries[summary_index].issue_count++;

	}

	// Print summaries
	for (int i = 0; i <= summary_index; i++) printf("Product ID: %d, Issue Count: %d\n", 
		summaries[i].product_id, summaries[i].issue_count);	
}


// Basic function for insertion of some test data into the structure, to ensure functionality
void insert_test_data(product_line** line_array) 
{
	// Line 1 Test Data
	line_array[0][0] = (product_line){1, 1001, {15, 10, 30}, 101, {404, "Leakage detected"}, {200, "Leak sealed"}, 501};
	line_array[0][1] = (product_line){1, 1002, {16, 11, 45}, 101, {402, "Incorrect labeling"}, {201, "Labels corrected"}, 502};
	line_array[0][2] = (product_line){1, 1003, {17, 9, 15}, 102, {401, "Temperature deviation"}, {202, "Temperature stabilized"}, 503};
	line_array[0][3] = (product_line){1, 1004, {18, 14, 0}, 103, {403, "Power issue"}, {203, "Power restored"}, 504};
	line_array[0][4] = (product_line){1, 1005, {19, 12, 30}, 103, {405, "Equipment failure"}, {204, "Equipment repaired"}, 505};
	line_array[0][5] = (product_line){1, 1006, {20, 13, 45}, 102, {406, "Software glitch"}, {205, "Software updated"}, 506};

	// Line 2 Test Data
	line_array[1][0] = (product_line){2, 2001, {12, 8, 30}, 201, {408, "Missing component"}, {206, "Component added"}, 507};
	line_array[1][1] = (product_line){2, 2002, {13, 12, 45}, 202, {410, "Improper seal"}, {207, "Seal reapplied"}, 508};
	line_array[1][2] = (product_line){2, 2003, {14, 10, 15}, 204, {409, "Cracked vial"}, {208, "Vial replaced"}, 509};
	line_array[1][3] = (product_line){2, 2004, {15, 16, 0}, 202, {414, "Documentation error"}, {209, "Documentation corrected"}, 510};
	line_array[1][4] = (product_line){2, 2005, {16, 14, 30}, 203, {412, "Labeling missing"}, {210, "Labeling completed"}, 511};
	line_array[1][5] = (product_line){2, 2006, {17, 15, 45}, 202, {413, "Test failure"}, {211, "Re-tested successfully"}, 512};

	// Line 3 Test Data
	line_array[2][0] = (product_line){3, 3001, {20, 9, 30}, 301, {415, "Calibration off"}, {212, "Calibration adjusted"}, 513};
	line_array[2][1] = (product_line){3, 3002, {21, 13, 45}, 302, {416, "Overfill"}, {213, "Fill level corrected"}, 514};
	line_array[2][2] = (product_line){3, 3003, {22, 11, 15}, 301, {414, "Underfill"}, {214, "Fill level adjusted"}, 515};
	line_array[2][3] = (product_line){3, 3004, {23, 15, 0}, 302, {417, "Label misprint"}, {215, "Labels reprinted"}, 516};
	line_array[2][4] = (product_line){3, 3005, {24, 10, 30}, 303, {419, "Incorrect ingredient"}, {216, "Ingredient corrected"}, 517};
	line_array[2][5] = (product_line){3, 3006, {25, 11, 45}, 303, {418, "Packing error"}, {217, "Repacked"}, 518};

	// Line 4 Test Data
	line_array[3][0] = (product_line){4, 4001, {25, 9, 30}, 402, {423, "Package tear"}, {215, "Package replaced"}, 513};
	line_array[3][1] = (product_line){4, 4002, {26, 14, 45}, 401, {422, "Machine jam"}, {213, "Jam cleared"}, 514};
	line_array[3][2] = (product_line){4, 4003, {27, 12, 15}, 402, {421, "Incorrect dosage"}, {214, "Dosage corrected"}, 515};
	line_array[3][3] = (product_line){4, 4004, {28, 17, 0}, 401, {423, "Package tear"}, {215, "Package replaced"}, 516};
	line_array[3][4] = (product_line){4, 4005, {29, 11, 30}, 403, {424, "Label error"}, {216, "Label fixed"}, 517};
	line_array[3][5] = (product_line){4, 4006, {31, 10, 45}, 402, {423, "Package tear"}, {215, "Package replaced"}, 518};
}

