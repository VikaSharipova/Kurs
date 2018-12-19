#include "utilities.h"

string input_string_with_retries(int retriesNum) {
	string buffer;
	int retries = 0;
	while (true) {
		try {
			cin >> buffer;
			break;
		}
		catch (int e) {
			if (retries <= retriesNum) {
				cout << "���������� ��� �����, ���������� �����. ���������� �������: " << retriesNum - retries << endl;
				retries++;
				cout << "���������� �����." << endl;
			}
			else {
				cout << "���������� ��� �����. ������� �����������, ���������� ���������." << endl;
				exit(1);
			}
		}
	}

	return buffer;
}

int input_int_with_retries(int retriesNum) {
	int retries = 0;
	int result;
	while (retries <= retriesNum) {
		try {
			result = stoi(input_string_with_retries(retriesNum));
			return result;
		}
		catch (int e) {
			cout << "������� �� �����, ���������� �����. ���������� �������: " << retriesNum - retries << endl;
			retries++;
		}
	}

	cout << "���������� ������� ���������, ���������� ���������.";
	exit(1);
}

int input_int_with_retries_and_borders(int retriesNum, int leftBorder, int rightBorder) {
	int retries = 0;
	int result;
	while (retries <= retriesNum) {
		try {
			result = stoi(input_string_with_retries(retriesNum));
			if (result >= leftBorder && result <= rightBorder) {
				return result;
			}
			else {
				cout << "�������� ���� ����� ��� ���������������� ������, ���������� �����. ���������� �������: " << retriesNum - retries << endl;
				retries++;
				continue;
			}
		}
		catch (int e) {
			cout << "������� �� �����, ���������� �����. ���������� �������: " << retriesNum - retries << endl;
			retries++;
		}
	}
	cout << "���������� ������� ���������, ���������� ���������.";
	exit(1);
}

void check_sportsmans_parameter(int parameter) {
	if (parameter >= LOWEST_SPORTSMAN_PARAMETER && parameter <= MAX_SPORTSMAN_PARAMETER) {
		return;
	}
	cout << "����� ������������ ��������. ���������� ���������.";
	exit(1);
}

