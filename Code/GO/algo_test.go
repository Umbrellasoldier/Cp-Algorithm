package main

import "testing"

func TestRectArea(t *testing.T) {
	r := rect{width: 10, height: 5}
	if got := r.area(); got != 50 {
		t.Fatalf("area() = %d, want 50", got)
	}
}

func TestRectPerim(t *testing.T) {
	r := rect{width: 10, height: 5}
	if got := r.perim(); got != 30 {
		t.Fatalf("perim() = %d, want 30", got)
	}
}
