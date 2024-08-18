package com.example.application.views.main;

import com.example.application.Apartamento;
import com.vaadin.flow.component.Text;
import com.vaadin.flow.component.button.Button;
import com.vaadin.flow.component.grid.Grid;
import com.vaadin.flow.component.orderedlayout.FlexLayout;
import com.vaadin.flow.component.textfield.TextField;
import com.vaadin.flow.router.Route;

import java.util.ArrayList;
import java.util.List;

@Route("")
public class MainView extends FlexLayout {
    private List<Apartamento> apartamentos = new ArrayList<>();
    private Grid<Apartamento> grid = new Grid<>(Apartamento.class);

    private Text atividade2 = new Text("Atividade 2 - Apartamentos"); // Elemento <h1>

    private TextField numeroTextField = new TextField("Número");
    private TextField moradorTextField = new TextField("Morador");
    private Button adicionarButton = new Button("Adicionar");
    private Button mostrarButton = new Button("Mostrar Apartamentos");

    public MainView() {
        adicionarButton.addClickListener(e -> adicionarApartamento());
        mostrarButton.addClickListener(e -> mostrarApartamentos());

        setJustifyContentMode(JustifyContentMode.CENTER); 

        setFlexDirection(FlexDirection.COLUMN);
        setAlignItems(Alignment.CENTER); 

        add(atividade2, numeroTextField, moradorTextField, adicionarButton, mostrarButton, grid);
    }

    private void adicionarApartamento() {
        int numero = Integer.parseInt(numeroTextField.getValue());
        String morador = moradorTextField.getValue();

        Apartamento apartamento = new Apartamento(numero, morador);
        apartamentos.add(apartamento);

        numeroTextField.clear();
        moradorTextField.clear();
    }

    private void mostrarApartamentos() {
        grid.setItems(apartamentos);
    }
}
