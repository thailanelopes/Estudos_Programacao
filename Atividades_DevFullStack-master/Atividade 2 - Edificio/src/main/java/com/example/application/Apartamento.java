package com.example.application;

public class Apartamento {
    private int numero;
    private String morador;

    public Apartamento(int numero, String morador) {
        this.numero = numero;
        this.morador = morador;
    }

    public int getNumero() {
        return numero;
    }

    public String getMorador() {
        return morador;
    }
}
