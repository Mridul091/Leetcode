class MyCalendarThree {
private:
	map<int, int> mp;
public:
	MyCalendarThree() {
			mp;
	} 
	int book(int start, int end) {
		mp[start]++;
		mp[end]--;
		int bookings = 0, sum = 0;
		for(auto &x : mp) {
			sum += x.second;
			bookings = max(bookings, sum);
		}
		return bookings;
	}
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */