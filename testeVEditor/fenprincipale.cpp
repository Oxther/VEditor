/*
    This file is part of VEditor.

    VEditor is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    VEditor is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with VEditor.  If not, see <http://www.gnu.org/licenses/>.

*/


#include "fenprincipale.h"
#include "aboutveditor.h"
#include "license.h"

FenPrincipale::FenPrincipale(int argc, char *argv[])
{

    qDebug() << "argc : " << argc;

    for(int i = 0; i < argc; i++){
        qDebug() << "argv" << i << " : " << argv[i];
    }

    // WINDOW

    setWindowTitle("VEditor");

    setWindowIcon(QIcon("images/VEditor.png"));


    // QTEXTEDIT

    texte = new QTextEdit(this);

    setCentralWidget(texte);

    if(argc > 1){
        QString nomFichier = argv[1];

            QFile fichier(nomFichier); // On crée un objet QFile en précisant le chemin du fichier
            if (fichier.open(QIODevice::ReadOnly))
            {
                texte->setText(fichier.readAll());

                setWindowTitle(nomFichier + " - VEditor");
            }
    }


    // Menu - "Fichier"
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
        // Menu - Fichier - Sous menus


            // Nouveau fichier
            actionNouveau = menuFichier->addAction("&Nouveau");
            actionNouveau->setShortcut(QKeySequence("Ctrl+N"));
            actionNouveau->setIcon(QIcon("images/nouveaudocument.png"));

            // Ouvrir
            actionOuvrir = menuFichier->addAction("&Ouvrir");
            actionOuvrir->setShortcut(QKeySequence("Ctrl+O"));
            actionOuvrir->setIcon(QIcon("images/ouvrirdocument.png"));


            // Enregistrer
            actionEnregistrer = menuFichier->addAction("Enregi&strer");
            actionEnregistrer->setShortcut(QKeySequence("Ctrl+S"));
            actionEnregistrer->setIcon(QIcon("images/enregistrer.png"));


            // Enregistrer sous
            actionEnregistrerSous = menuFichier->addAction("Enregistrer sous");
            actionEnregistrerSous->setShortcut(QKeySequence("-"));
            actionEnregistrerSous->setIcon(QIcon("images/enregistrersous.png"));


            // Imprimer
            actionImprimer = menuFichier->addAction("Imprimer");
            actionImprimer->setShortcut(QKeySequence("-"));
            actionImprimer->setIcon(QIcon("images/imprimer.png"));

            // enregistrer en texte brut ou en html
            brutOuHtml = menuFichier->addAction("enregistrer en texte brut");
            brutOuHtml->setCheckable(true);

            // Quitter
            actionQuitter = menuFichier->addAction("&Quitter");
            actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
            actionQuitter->setIcon(QIcon("images/quitter.png"));
             // CONNEXION

    // Menu "Edition"
    QMenu *menuEdition = menuBar()->addMenu("&Edition");
        // Menu Edition - Sous menus


            // Undo
            actionUndo = menuEdition->addAction("&Undo");
            actionUndo->setIcon(QIcon("images/undo.png"));
            actionUndo->setShortcut(QKeySequence("Ctrl+Z"));
            actionUndo->setDisabled(true);

            // Redo
            actionRedo = menuEdition->addAction("&Redo");
            actionRedo->setIcon(QIcon("images/redo.png"));
            actionRedo->setShortcut(QKeySequence("Ctrl+Shift+Z"));
            actionRedo->setDisabled(true);

            // Clear
            actionClear = menuEdition->addAction("Clear");
            actionClear->setShortcut(QKeySequence("Ctrl+D"));

            // Gras
            QMenu *menuActionBold = new QMenu;

            styleGras = menuEdition->addAction("Gras");
            styleGras->setIcon(QIcon("images/gras.png"));
            styleGras->setCheckable(true);
            styleGras->setMenu(menuActionBold);

            styleThin = menuActionBold->addAction("thin");
            styleThin->setCheckable(true);

            styleExtraLight = menuActionBold->addAction("extra light");
            styleExtraLight->setCheckable(true);

            styleLight = menuActionBold->addAction("light");
            styleLight->setCheckable(true);

            styleMedium = menuActionBold->addAction("medium");
            styleMedium->setCheckable(true);

            styleDemiBold = menuActionBold->addAction("demi bold");
            styleDemiBold->setCheckable(true);

            styleExtraBold = menuActionBold->addAction("extra bold");
            styleExtraBold->setCheckable(true);

            styleBlack = menuActionBold->addAction("black");
            styleBlack->setCheckable(true);


            // Italique
            styleItalique = menuEdition->addAction("Italique");
            styleItalique->setIcon(QIcon("images/italique.png"));
            styleItalique->setCheckable(true);


            // Souligne
            styleSouligne = menuEdition->addAction("Souligné");
            styleSouligne->setIcon(QIcon("images/souligner.png"));
            styleSouligne->setCheckable(true);


            // Qt::AlignLeft
            actionAlignLeft = menuEdition->addAction("AlignLeft");
            actionAlignLeft->setIcon(QIcon("images/alignLeft"));


            // Qt::AlignRight
            actionAlignRight = menuEdition->addAction("AlignRight");
            actionAlignRight->setIcon(QIcon("images/alignRight"));



            // Qt::AlignJustify
            actionAlignJustify = menuEdition->addAction("AlignJustify");
            actionAlignJustify->setIcon(QIcon("images/alignJustify"));



            // Qt::AlignCenter
            actionAlignCenter = menuEdition->addAction("AlignCenter");
            actionAlignCenter->setIcon(QIcon("images/alignCenter"));




            // Barre
            //QAction *styleBarre = menuEdition->addAction("Barré");
            //styleBarre->setIcon(QIcon("images/barré.png"));
            //styleBarre->setCheckable(true);

            // Couleur
            styleCouleur = menuEdition->addAction("Couleur");
            styleCouleur->setIcon(QIcon("images/couleur.png"));

            styleTexteBackground = menuEdition->addAction("surligner");



            actionSelectAll = menuEdition->addAction("selectionner tout");

            actionCopy = menuEdition->addAction("copier");

            actionCut = menuEdition->addAction("couper");




    // Menu "Affichage"
    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

            // cacher la barre
            QAction *cacherToolBarHaute = new QAction("Cacher la barre d'outils haute", this);
            cacherToolBarHaute->setCheckable(true);
            menuAffichage->addAction(cacherToolBarHaute);


            QAction *cacherToolBarBasse = new QAction("Cacher la barre d'outils basse", this);
            cacherToolBarBasse->setCheckable(true);
            menuAffichage->addAction(cacherToolBarBasse);


            QAction *afficherStatusBar = new QAction("Afficher la barre de status", this);
            afficherStatusBar->setCheckable(true);
            menuAffichage->addAction(afficherStatusBar);

            actionDeverrouillerToolBar = new QAction("Déverrouiller les barres d'outils", this);
            actionDeverrouillerToolBar->setCheckable(true);
            menuAffichage->addAction(actionDeverrouillerToolBar);


            QAction *actionStyleDark = new QAction("Appliquer un thème sombre", this);
            actionStyleDark->setCheckable(true);
            menuAffichage->addAction(actionStyleDark);






    // Menu "Aide"
    QMenu *menuAide = menuBar()->addMenu("&Aide");

            // About QT
            QAction *actionAboutQT = new QAction("&A propos de QT", this);
            menuAide->addAction(actionAboutQT);
            actionAboutQT->setIcon(QIcon("images/QT.png"));

            // About VEditor
            QAction *actionAboutVEditor = new QAction("&A propos de VEditor", this);
            menuAide->addAction(actionAboutVEditor);
            actionAboutVEditor->setIcon(QIcon("images/VEditor.png"));

            // License
            QAction *actionLicense = new QAction("license", this);
            menuAide->addAction(actionLicense);
            actionLicense->setIcon(QIcon("images/GPLv3"));



    // barre d'outils
    creerBarreDoutils();

    // Barre de status
    creerBarreStatus();



    // Connection au slots
        // menu fichier
        connect(actionNouveau, SIGNAL(triggered()), this, SLOT(nouveauDocument()));
        connect(actionOuvrir, SIGNAL(triggered()), this, SLOT(ouvrirDocument()));
        connect(actionEnregistrer, SIGNAL(triggered()), this, SLOT(enregistrer()));
        connect(actionEnregistrerSous, SIGNAL(triggered()), this, SLOT(enregistrerSous()));
        connect(brutOuHtml, SIGNAL(triggered()), this, SLOT(slotbrutOuHtml()));
        connect(actionImprimer, SIGNAL(triggered()), this, SLOT(imprimer()));
        connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));


        // menu edition
        connect(actionUndo, SIGNAL(triggered()), texte, SLOT(undo()));
        connect(actionRedo, SIGNAL(triggered()), texte, SLOT(redo()));
        connect(texte, SIGNAL(redoAvailable(bool)), this, SLOT(redoAvailable(bool)));
        connect(texte, SIGNAL(undoAvailable(bool)), this, SLOT(undoAvailable(bool)));
        connect(actionClear, SIGNAL(triggered()), this, SLOT(clear()));
        connect(styleGras, SIGNAL(triggered(bool)), this, SLOT(mettreEnGras(bool)));
        connect(styleThin, SIGNAL(triggered(bool)), this, SLOT(setThin(bool)));
        connect(styleExtraLight, SIGNAL(triggered(bool)), this, SLOT(setExtraLight(bool)));
        connect(styleLight, SIGNAL(triggered(bool)), this, SLOT(setLight(bool)));
        connect(styleMedium, SIGNAL(triggered(bool)), this, SLOT(setMedium(bool)));
        connect(styleDemiBold, SIGNAL(triggered(bool)), this, SLOT(setDemiBold(bool)));
        connect(styleExtraBold, SIGNAL(triggered(bool)), this, SLOT(setExtraBold(bool)));
        connect(styleBlack, SIGNAL(triggered(bool)), this, SLOT(setBlack(bool)));
        connect(texte, SIGNAL(selectionChanged()), this, SLOT(deselection()));
        connect(styleItalique, SIGNAL(triggered(bool)), texte, SLOT(setFontItalic(bool)));
        connect(styleSouligne, SIGNAL(triggered(bool)), texte, SLOT(setFontUnderline(bool)));
        connect(texte, SIGNAL(selectionChanged()), this, SLOT(deselection()));
        connect(actionAlignLeft, SIGNAL(triggered()), this, SLOT(setAlignmentLeft()));
        connect(actionAlignRight, SIGNAL(triggered()), this, SLOT(setAlignmentRight()));
        connect(actionAlignJustify, SIGNAL(triggered()), this, SLOT(setAlignmentJustify()));
        connect(actionAlignCenter, SIGNAL(triggered()), this, SLOT(setAlignmentCenter()));
        connect(styleCouleur, SIGNAL(triggered()), this, SLOT(changerCouleur()));
        connect(styleTexteBackground, SIGNAL(triggered()), this, SLOT(setTexteBackground()));
        connect(actionSelectAll, SIGNAL(triggered()), texte, SLOT(selectAll()));
        connect(actionCopy, SIGNAL(triggered()), texte, SLOT(copy()));
        connect(actionCut, SIGNAL(triggered()), texte, SLOT(cut()));




        // menu affichage
        connect(actionDeverrouillerToolBar, SIGNAL(triggered(bool)), this, SLOT(deverrouillerToolBar(bool)));
        connect(actionStyleDark, SIGNAL(triggered(bool)), this, SLOT(styleDarked(bool)));

        // menu aide
        connect(actionAboutQT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
        connect(actionAboutVEditor, SIGNAL(triggered()), this, SLOT(aboutVEditor()));
        connect(actionLicense, SIGNAL(triggered()), this, SLOT(License()));

    // barre d'outils

        //haute
        connect(cacherToolBarHaute, SIGNAL(triggered(bool)), toolBar, SLOT(setHidden(bool)));
        connect(cacherToolBarHaute, SIGNAL(triggered(bool)), this, SLOT(desactiveDeverouillerToolBar()));

        //basse
        connect(cacherToolBarBasse, SIGNAL(triggered(bool)), toolBar2, SLOT(setHidden(bool)));
        connect(cacherToolBarBasse, SIGNAL(triggered(bool)), this, SLOT(desactiveDeverouillerToolBar()));

    // barre de status
    connect(afficherStatusBar, SIGNAL(triggered(bool)), statusBar, SLOT(setVisible(bool)));
    connect(texte, SIGNAL(cursorPositionChanged()), this, SLOT(positionCursorChange()));

    // STYLE SHEET

    styleDark = settingsToolBar->value("style/current").toInt();

    appliquerStyle(styleDark);

    if(currentStyle)
    {

        actionStyleDark->setChecked(true);

    }

    else
    {


        actionStyleDark->setChecked(false);

    }



}


// SLOT enregistrement des options
void FenPrincipale::closeEvent(QCloseEvent *event)
{

    settingsToolBar->setValue("style/current", currentStyle);

    event->accept();

}

// SLOT Style dark
void FenPrincipale::styleDarked(bool styleDarkTrueFalse)
{
    appliquerStyle(styleDarkTrueFalse);
}

// SLOT position du curseur
void FenPrincipale::positionCursorChange()
{

    QRect cursorXY = texte->cursorRect();

    int ligne = cursorXY.height();

    QString ligneStr = QString::number(ligne);
    statusBar->showMessage(ligneStr);
}

// SLOT Désactiver déverrouiller les barre d'outils
void FenPrincipale::desactiveDeverouillerToolBar()
{

    if(toolBar->isHidden() && toolBar2->isHidden())
    {

        actionDeverrouillerToolBar->setDisabled(true);

    }

    else

    {

        actionDeverrouillerToolBar->setDisabled(false);

    }


}


// SLOT imprimer
void FenPrincipale::imprimer()
{

    QPrinter * imprimante = new QPrinter;

    QPrintDialog * dialogue = new QPrintDialog(imprimante, this);

    if(dialogue->exec() == QDialog::Accepted)
        texte->print(imprimante);

}


// SLOT nouveauDocument
void FenPrincipale::nouveauDocument()
{
    nombreDoc = 0;

    nombreDocQString = QString::number(nombreDoc);

    QString titreFenetreNewDoc = "sans titre " + nombreDoc;

    nombreDeCaracteresActuel = texte->toPlainText().size();

    if(nombreDeCaracteresActuel != nombreDeCaracteres or nomFichier.isEmpty())

    {

        int reponse = QMessageBox::question(this, "Enregistrer", "Voulez vous sauvegarder les modifications?", QMessageBox ::Yes | QMessageBox::No);


        if (reponse == QMessageBox::Yes)

        {

            QString texteEnHtml = texte->toHtml(); // Ici on stocke dans une variable la "version html" de ton texte

            if(nomFichier.isEmpty())

            {

            nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer...", "Sans titre.txt"); // Ici on stocke dans la variable le chemin et le nom du fichier choisi par l'utilisateur via le dialogue

            }

            QFile fichier(nomFichier); // On crée un objet QFile en indiquant le chemin du fichier

            if (fichier.open(QIODevice::WriteOnly))
            {
                QTextStream out(&fichier); // Alors on crée un objet QTextStream (flux de texte) nommé out auquel on renseigne l'adresse en mémoire du fichier ouvert (ici "&fichier")
                out << texteEnHtml; // C'est simple on fait "entrer" dans le flux le texte en html !
                nombreDeCaracteres = texte->toPlainText().size();
            }


            texte->clear();

            nomFichier = "";

            setWindowTitle(titreFenetreNewDoc);


        }

        else if (reponse == QMessageBox::No)

        {

            texte->clear();

            nomFichier = "";

            setWindowTitle(titreFenetreNewDoc);


        }



    }

    else

    {

        texte->clear();

        nomFichier = "";

        setWindowTitle(titreFenetreNewDoc);

    }

}

// SLOT ouvrirDocument
void FenPrincipale::ouvrirDocument()
{
    QString nomFichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString()); // On récupère donc dans nomFichier le chemin du fichier à ouvrir via le dialogue
        QFile fichier(nomFichier); // On crée encore et toujours notre objet QFile en précisant le chemin du fichier
        if (fichier.open(QIODevice::ReadOnly)) // Cette fois-ci c'est le flag ReadOnly qui est utilisé, cependant lui si le fichier sélectionné n'existe pas il retournera irrémédiablement false
        {
            texte->setText(fichier.readAll()); // Là on dit au QTextEdit de récupérer TOUTES les données du fichier ouvert via readAll(),la fonction setText() retournera un texte riche et non plus en html

            setWindowTitle(nomFichier + " - VEditor");
        }
}


// SLOT enregistrer
void FenPrincipale::enregistrer()
{

    QString texteEnHtml = texte->toHtml(); // Ici on stocke dans une variable la "version html" du texte

    if(nomFichier.isEmpty())

    {

    nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer...", "Sans titre 1.txt"); // Ici on stocke dans la variable le chemin et le nom du fichier choisi par l'utilisateur via le dialogue

    }

    QFile fichier(nomFichier); // On crée un objet QFile en indiquant le chemin du fichier

    if (fichier.open(QIODevice::WriteOnly))
    {
        QTextStream out(&fichier); // Alors on crée un objet QTextStream (flux de texte) nommé out auquel on renseigne l'adresse en mémoire du fichier ouvert (ici "&fichier")
        out << texteEnHtml; // on fait "entrer" dans le flux le texte en html
        nombreDeCaracteres = texte->toPlainText().size();
    }



}

// SLOT enregistrerSous
void FenPrincipale::enregistrerSous()
{
        QString texteEnHtml = texte->toHtml(); // on stocke dans une variable la "version html" du texte

        nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer...", "Sans titre 1.txt"); // on stocke dans la variable le chemin et le nom du fichier choisi par l'utilisateur via le dialogue

        QFile fichier(nomFichier); // On crée un objet QFile en indiquant le chemin du fichier

        if (fichier.open(QIODevice::WriteOnly))
        {
            QTextStream out(&fichier); // Alors on crée un objet QTextStream (flux de texte) nommé out auquel on renseigne l'adresse en mémoire du fichier ouvert (ici "&fichier")
            out << texteEnHtml; // on fait "entrer" dans le flux le texte en html
            nombreDeCaracteres = texte->toPlainText().size();
        }
}


// SLOT changerCouleur
void FenPrincipale::changerCouleur()
{
    QColor couleur = QColorDialog::getColor(Qt::white, this); // la variable va stocker la réponse du dialogue qui renverra un QColor

    texte->setTextColor(couleur); // Lequel nous passons à la fonction setTextColor qui définit la couleur du texte
}


// SLOT change texte background
void FenPrincipale::setTexteBackground()
{
    QColor couleur = QColorDialog::getColor(Qt::white, this); // la variable va stocker la réponse du dialogue qui renverra un QColor

    texte->setTextBackgroundColor(couleur); // Lequel nous passons à la fonction setTextColor qui définit la couleur du texte
}


// SLOT verrouiller la barre
void FenPrincipale::deverrouillerToolBar(bool vrai)

{
   if (!vrai)
   {

       toolBar->setMovable(false);
       toolBar2->setMovable(false);

   }
   else
   {

       toolBar->setMovable(true);
       toolBar2->setMovable(true);

   }

}


// SLOT mettreEnGras
void FenPrincipale::mettreEnGras(bool ok)
{
    if (ok)
    {
        texte->setFontWeight(QFont::Bold);
    }
    else
    {
        texte->setFontWeight(QFont::Normal);
    }

    //styleGras->setChecked(false);
    styleThin->setChecked(false);
    styleExtraLight->setChecked(false);
    styleLight->setChecked(false);
    styleMedium->setChecked(false);
    styleDemiBold->setChecked(false);
    styleExtraBold->setChecked(false);
    styleBlack->setChecked(false);
}

void FenPrincipale::setThin(bool ok)
{
    if (ok)
    {
        texte->setFontWeight(QFont::Thin);
    }
    else
    {
        texte->setFontWeight(QFont::Normal);
    }

    styleGras->setChecked(false);
    //styleThin->setChecked(false);
    styleExtraLight->setChecked(false);
    styleLight->setChecked(false);
    styleMedium->setChecked(false);
    styleDemiBold->setChecked(false);
    styleExtraBold->setChecked(false);
    styleBlack->setChecked(false);
}

void FenPrincipale::setExtraLight(bool ok)
{
    if (ok)
    {
        texte->setFontWeight(QFont::ExtraLight);
    }
    else
    {
        texte->setFontWeight(QFont::Normal);
    }

    styleGras->setChecked(false);
    styleThin->setChecked(false);
    //styleExtraLight->setChecked(false);
    styleLight->setChecked(false);
    styleMedium->setChecked(false);
    styleDemiBold->setChecked(false);
    styleExtraBold->setChecked(false);
    styleBlack->setChecked(false);
}

void FenPrincipale::setLight(bool ok)
{
    if (ok)
    {
        texte->setFontWeight(QFont::Light);
    }
    else
    {
        texte->setFontWeight(QFont::Normal);
    }

    styleGras->setChecked(false);
    styleThin->setChecked(false);
    styleExtraLight->setChecked(false);
    //styleLight->setChecked(false);
    styleMedium->setChecked(false);
    styleDemiBold->setChecked(false);
    styleExtraBold->setChecked(false);
    styleBlack->setChecked(false);
}

void FenPrincipale::setMedium(bool ok)
{
    if (ok)
    {
        texte->setFontWeight(QFont::Medium);
    }
    else
    {
        texte->setFontWeight(QFont::Normal);
    }

    styleGras->setChecked(false);
    styleThin->setChecked(false);
    styleExtraLight->setChecked(false);
    styleLight->setChecked(false);
    //styleMedium->setChecked(false);
    styleDemiBold->setChecked(false);
    styleExtraBold->setChecked(false);
    styleBlack->setChecked(false);
}

void FenPrincipale::setDemiBold(bool ok)
{
    if (ok)
    {
        texte->setFontWeight(QFont::DemiBold);
    }
    else
    {
        texte->setFontWeight(QFont::Normal);
    }

    styleGras->setChecked(false);
    styleThin->setChecked(false);
    styleExtraLight->setChecked(false);
    styleLight->setChecked(false);
    styleMedium->setChecked(false);
    //styleDemiBold->setChecked(false);
    styleExtraBold->setChecked(false);
    styleBlack->setChecked(false);
}

void FenPrincipale::setExtraBold(bool ok)
{
    if (ok)
    {
        texte->setFontWeight(QFont::ExtraBold);
    }
    else
    {
        texte->setFontWeight(QFont::Normal);
    }

    styleGras->setChecked(false);
    styleThin->setChecked(false);
    styleExtraLight->setChecked(false);
    styleLight->setChecked(false);
    styleMedium->setChecked(false);
    styleDemiBold->setChecked(false);
    //styleExtraBold->setChecked(false);
    styleBlack->setChecked(false);
}

void FenPrincipale::setBlack(bool ok)
{
    if (ok)
    {
        texte->setFontWeight(QFont::Black);
    }
    else
    {
        texte->setFontWeight(QFont::Normal);
    }

    styleGras->setChecked(false);
    styleThin->setChecked(false);
    styleExtraLight->setChecked(false);
    styleLight->setChecked(false);
    styleMedium->setChecked(false);
    styleDemiBold->setChecked(false);
    styleExtraBold->setChecked(false);
    //styleBlack->setChecked(false);
}


// SLOT nombre du spinbox
void FenPrincipale::nombreSpinBox()
{

    taillepolice = texte->fontPointSize();

    spinBox->blockSignals(true);

    spinBox->setValue(taillepolice);

    spinBox->blockSignals(false);





}

// SLOT déselection
void FenPrincipale::deselection()
{

    styleGras->setChecked(false);
    styleItalique->setChecked(false);
    styleSouligne->setChecked(false);

}

// SLOT clear

void FenPrincipale::clear()
{

    int reponse = QMessageBox::question(this, "Effacer tout", "Voulez vous vraiment tout effacer?", QMessageBox ::Yes | QMessageBox::No);


    if (reponse == QMessageBox::Yes)

    {

        texte->clear();

    }

}

// texte brut ou html
void FenPrincipale::slotbrutOuHtml()
{
    styleSouligne->setDisabled(true);
    styleItalique->setDisabled(true);
    styleGras->setDisabled(true);
}

// SLOT taille police
void FenPrincipale::changerTaille(int taille)
{

    texte->setFontPointSize(taille);

}


// SLOT changer police
void FenPrincipale::policeChange(QFont font)
{

    int currentFontSize = texte->fontPointSize();
    texte->setCurrentFont(font);
    texte->setFontPointSize(currentFontSize);

}


// SLOT alignement left
void FenPrincipale::setAlignmentLeft()
{
    texte->setAlignment(Qt::AlignLeft);
}


// SLOT alignement right
void FenPrincipale::setAlignmentRight()
{
    texte->setAlignment(Qt::AlignRight);
}


// SLOT alignement center
void FenPrincipale::setAlignmentCenter()
{
    texte->setAlignment(Qt::AlignCenter);
}


// SLOT alignement justify
void FenPrincipale::setAlignmentJustify()
{
    texte->setAlignment(Qt::AlignJustify);
}


//implementation de About VEditor
void FenPrincipale::aboutVEditor()

{

    AboutVEditor *Apropos = new AboutVEditor;
    Apropos->show();

}

// SLOT about License

void FenPrincipale::License()
{
    AboutLicense *fenetreLicense = new AboutLicense(this);
    fenetreLicense->exec();
}

void FenPrincipale::appliquerStyle(int style)
{
    if(style)
    {

        texte->setStyleSheet("color: #ffffff; background-color: #232629; border-radius: 2");

        setStyleSheet("QTextEdit { border: 1px solid #3daee9 } QTextEdit:hover { border: 1px solid #62c0f1 }");

        toolBar->setStyleSheet("color: #ffffff; background-color: #31363b");

        toolBar2->setStyleSheet("color: #ffffff; background-color: #31363b");

        statusBar->setStyleSheet("color: #ffffff; background-color: #31363b");

        menuBar()->setStyleSheet("color: #ffffff; background-color: #31363b");

        // Application d'icones claires

        actionNouveau->setIcon(QIcon("images/nouveaudocumentb.png"));

        actionOuvrir->setIcon(QIcon("images/ouvrirdocumentb.png"));

        actionEnregistrer->setIcon(QIcon("images/enregistrerb.png"));

        actionEnregistrerSous->setIcon(QIcon("images/enregistrersousb.png"));

        actionImprimer->setIcon(QIcon("images/imprimerb.png"));

        actionQuitter->setIcon(QIcon("images/quitterb.png"));

        actionUndo->setIcon(QIcon("images/undob.png"));

        actionRedo->setIcon(QIcon("images/redob.png"));

        styleGras->setIcon(QIcon("images/grasb.png"));

        styleItalique->setIcon(QIcon("images/italiqueb.png"));

        styleSouligne->setIcon(QIcon("images/soulignerb.png"));

        actionAlignLeft->setIcon(QIcon("images/alignLeftb"));

        actionAlignRight->setIcon(QIcon("images/alignRightb"));

        actionAlignJustify->setIcon(QIcon("images/alignJustifyb"));

        actionAlignCenter->setIcon(QIcon("images/alignCenterb"));

        styleCouleur->setIcon(QIcon("images/couleurb.png"));

        currentStyle = 1;
    }
    else
    {
        texte->setStyleSheet("");

        toolBar->setStyleSheet("");

        toolBar2->setStyleSheet("");

        statusBar->setStyleSheet("");

        menuBar()->setStyleSheet("");

        // Application d'icones sombres

        actionNouveau->setIcon(QIcon("images/nouveaudocument.png"));

        actionOuvrir->setIcon(QIcon("images/ouvrirdocument.png"));

        actionEnregistrer->setIcon(QIcon("images/enregistrer.png"));

        actionEnregistrerSous->setIcon(QIcon("images/enregistrersous.png"));

        actionImprimer->setIcon(QIcon("images/imprimer.png"));

        actionQuitter->setIcon(QIcon("images/quitter.png"));

        actionUndo->setIcon(QIcon("images/undo.png"));

        actionRedo->setIcon(QIcon("images/redo.png"));

        styleGras->setIcon(QIcon("images/gras.png"));

        styleItalique->setIcon(QIcon("images/italique.png"));

        styleSouligne->setIcon(QIcon("images/souligner.png"));

        actionAlignLeft->setIcon(QIcon("images/alignLeft"));

        actionAlignRight->setIcon(QIcon("images/alignRight"));

        actionAlignJustify->setIcon(QIcon("images/alignJustify"));

        actionAlignCenter->setIcon(QIcon("images/alignCenter"));

        styleCouleur->setIcon(QIcon("images/couleur.png"));

        currentStyle = 0;

    }


}

// SLOT creer les menus
void FenPrincipale::creerMenu()
{

}
// SLOT creer les barres
void FenPrincipale::creerBarreDoutils()
{
    // LA BARRE D'OUTILS HAUTE
    toolBar = new QToolBar("Afficher la barre d'outils haute");
    addToolBar(Qt::TopToolBarArea, toolBar);
    settingsToolBar = new QSettings("VEditor", "toolBar");
    toolBar->setMovable(false);
    toolBar->addAction(actionNouveau);
    toolBar->addAction(actionOuvrir);
    toolBar->addAction(actionEnregistrer);
    toolBar->addAction(actionEnregistrerSous);
    toolBar->addAction(actionImprimer);
    toolBar->addSeparator();

    spinBox = new QSpinBox;
    spinBox->setRange(10, 100);
    spinBox->setAccelerated(true);
    toolBar->addWidget(spinBox);
    connect(spinBox , SIGNAL(valueChanged(int)), this,  SLOT(changerTaille(int)));
    connect(texte, SIGNAL(selectionChanged()), this, SLOT(nombreSpinBox()));

    toolBar->addAction(styleGras);
    toolBar->addAction(styleItalique);
    toolBar->addAction(styleSouligne);
    //toolBar->addAction(styleBarre);
    toolBar->addAction(styleCouleur);
    toolBar->addAction(styleTexteBackground);
    toolBar->addSeparator();
    toolBar->addAction(actionAlignLeft);
    toolBar->addAction(actionAlignRight);
    toolBar->addAction(actionAlignCenter);
    toolBar->addAction(actionAlignJustify);
    toolBar->addSeparator();
    toolBar->addAction(actionUndo);
    toolBar->addAction(actionRedo);



    // LA BARRE D'OUTILS BASSE  
    toolBar2 = new QToolBar("Afficher barre d'outils basse");
    addToolBar(Qt::BottomToolBarArea, toolBar2);
    toolBar2->setMovable(false);
    toolBar2->addAction(actionSelectAll);
    toolBar2->addAction(actionCopy);
    toolBar2->addAction(actionCut);
    toolBar2->addAction(actionClear);


}
// SLOT creer barre de status
void FenPrincipale::creerBarreStatus()
{
    statusBar = new QStatusBar;
    statusBar->showMessage("");
    setStatusBar(statusBar);
    statusBar->setHidden(true);
    resize(548, 600);
}


void FenPrincipale::redoAvailable(bool yes)
{
    if(yes){
        actionRedo->setDisabled(false);
    }
    else{
        actionRedo->setDisabled(true);
    }
}

void FenPrincipale::undoAvailable(bool yes)
{
    if(yes){
        actionUndo->setDisabled(false);
    }
    else{
        actionUndo->setDisabled(true);
    }
}
