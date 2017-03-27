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

#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QtGui>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QtWidgets>
#include <QMessageBox>
#include <QTextStream>
#include <QApplication>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>
#include <QSettings>

/*
 * Classe de creation de la fenêtre principale
 * Elle herite de QmainWindow
 */


class FenPrincipale : public QMainWindow
{
    Q_OBJECT

    public:
        FenPrincipale(int argc, char *argv[]);

    private:
    void creerMenu();
    void creerBarreDoutils();
    void creerBarreStatus();
    void appliquerStyle(int style);




    private slots:
    void imprimer();
    void nouveauDocument();
    void ouvrirDocument();
    void enregistrer();
    void enregistrerSous();
    void changerCouleur();
    void setTexteBackground();
    void mettreEnGras(bool ok);
    void setThin(bool ok);
    void setExtraLight(bool ok);
    void setLight(bool ok);
    void setMedium(bool ok);
    void setDemiBold(bool ok);
    void setExtraBold(bool ok);
    void setBlack(bool ok);
    void changerTaille(int);
    void nombreSpinBox();
    void policeChange(QFont font);
    void setAlignmentLeft();
    void setAlignmentRight();
    void setAlignmentCenter();
    void setAlignmentJustify();
    void aboutVEditor();
    void License();
    void deverrouillerToolBar(bool vrai);
    void desactiveDeverouillerToolBar();
    void deselection();
    void redoAvailable(bool yes);
    void undoAvailable(bool yes);
    void clear();
    void styleDarked(bool styleDarkTrueFalse);
    void positionCursorChange();
    void slotbrutOuHtml();

    protected:
    void closeEvent(QCloseEvent *event);

    private:
    QTextEdit *texte; // la zone de texte
    QToolBar *toolBar; // barre d'outils haute
    QToolBar *toolBar2; // barre d'outils basse
    QStatusBar *statusBar; // barre de status
    QSpinBox *spinBox; // spinbox pour choisir la taille de la police
    QString nomFichier; // chemin du fichier enregistré
    int taillepolice; // taille de la police
    int nombreDeCaracteres;
    int nombreDeCaracteresActuel;
    int nombreDoc;
    int currentStyle; // le style actuel de l'application
    QString nombreDocQString;
    QAction *actionDeverrouillerToolBar;
    QAction *actionNouveau;
    QAction *actionOuvrir;
    QAction *actionEnregistrer;
    QAction *actionEnregistrerSous;
    QAction *actionImprimer;
    QAction *actionQuitter;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionClear;
    QAction *styleGras;
    QAction *styleThin;
    QAction *styleExtraLight;
    QAction *styleLight;
    QAction *styleMedium;
    QAction *styleDemiBold;
    QAction *styleExtraBold;
    QAction *styleBlack;
    QAction *styleItalique;
    QAction *styleSouligne;
    QAction *actionAlignLeft;
    QAction *actionAlignRight;
    QAction *actionAlignJustify;
    QAction *actionAlignCenter;
    QAction *styleCouleur;
    QAction *styleTexteBackground;
    QAction *actionSelectAll;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *brutOuHtml;
    QSettings *settingsToolBar;
    bool styleDark;


};

#endif // FENPRINCIPALE_H
