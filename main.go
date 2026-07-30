package main

import "fmt"

type Registers struct {
	a uint8
	b uint8
	c uint8
	d uint8
	e uint8
	f uint8
	g uint8
	h uint8
}

func (r* Registers) New() *Registers {
	fmt.Println("Initializing...")
	return &Registers{}
}

func (r* Registers) GetBC() uint16 {
	return (uint16(r.b) << 8) | uint16(r.c)
}

func (r* Registers) SetBC(value uint16) {
	r.b = uint8((value & 0xFF00) >> 8)
	r.c = uint8(value & 0xFF) 
}

func main() {
	reg := (&Registers{}).New()
	reg.SetBC(10)
	fmt.Println("Hello World!", reg.GetBC())
}