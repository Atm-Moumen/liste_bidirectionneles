#include <iostream>
#include <stdlib.h>
using namespace std;
struct elemt{
  int val;
  elemt *suiv;
  elemt *prec;
};
void cree_list(elemt *&tete,int tai)
{
    elemt *p,*q;
    p=tete;
    for(int i=0;i<tai;i++)
    {
        p = (elemt*)malloc(sizeof(elemt));
        cout<<"donner la valeur: ";
        cin>>p->val;
        p->suiv=NULL;
        if(tete==NULL)
         {
             p->suiv=tete;
             tete=p;
         }
         else{
            q->suiv=p;
         }
         q=p;

    }
}

void affich_liste(elemt *&tete)
{
    elemt *p;
    cout<<"-------------------------------------------------"<<endl;
    if(tete==NULL)
        cout<<"la liste est vide!!!\n";
    else
    {
    p=tete;
    while(p!=NULL)
    {
        cout<<p->val<<endl;
        p=p->suiv;
    }
    }
    cout<<"-----------------------------------------------"<<endl;
}
int taill_liste(elemt *tete)
{
    int tai=0;
    elemt *p;
    p=tete;
    while(p!=NULL)
    {
        tai++;
        p=p->suiv;
    }
    return tai;
}
int nb_occ(elemt *tete,int v)
{
    elemt *p;int nb=0;
    p=tete;
    while(p!=NULL)
    {
       if (p->val==v)
       {
            nb++;
       }
       p=p->suiv;
    }
    return nb;
}
bool si_trie(elemt *tete)
{
    elemt *p;
    p=tete;
    while(p->suiv!=NULL)
    {
        if(tete==NULL)
            return false;
        else{
                if((p->val)>(p->suiv->val))
                   return false;
        }
        p=p->suiv;
    }
    return true;

}
void insrt_tete(elemt *&tete,int valeur)
{
    elemt *p;
    p = (elemt*)malloc(sizeof(elemt));
    p->val=valeur;
    p->suiv=tete;
    tete=p;
    cout<<"l insertion a faite avec succes.\n";
}
void supprimer_tete(elemt *&tete)
{
    elemt *p;
    if(tete==NULL)
        cout<<"la liste est vide!!!\n";
    else{
        p=tete->suiv;
        delete tete;
        tete=p;
    }
}
void supprimer_liste(elemt *&tete)
{
    while(tete!=NULL)
    {
       supprimer_tete(tete);

    }
    cout<<"la liste a ete supprime!!!!\n";
}
void insrt_queue(elemt *&tete,int valeur)
{

    if(tete==NULL)
    {
        insrt_tete(tete,valeur);
    }
    else
    {elemt *p,*nov;
    nov = (elemt*)malloc(sizeof(elemt));
    nov->val=valeur;
    nov->suiv=NULL;
    p=tete;
    while(p->suiv!=NULL)
    {
        p=p->suiv;
    }
    p->suiv=nov;
    cout<<"l insertion a faite avec succes.\n";
    }

}
elemt* acces_pos(elemt *tete,int pos)
{
  elemt *p;
  p=tete;
  while((p!=NULL)&(pos!=1))
  {
      p=p->suiv;
      pos--;
  }
  return p;
}
void insrt_par_pos(elemt *&tete,int val,int pos)
{
  elemt *p,*prec;
  if(pos==1)
        insrt_tete(tete,val);
  else
  { prec=acces_pos(tete,pos-1);
    if(prec!=NULL)
    {
        p = (elemt*)malloc(sizeof(elemt));
        p->val=val;
        p->suiv=prec->suiv;
        prec->suiv=p;
    }


  }
}
void supprimer_par_pos(elemt *&tete,int pos)
{
    if(pos==1)
        supprimer_tete(tete);
    else{ elemt *prec;
       prec=acces_pos(tete,pos-1);
       if(prec!=NULL)
       { elemt *p;
          p=prec->suiv;
          if(p!=NULL)
          {
              prec->suiv=p->suiv;
              delete p;
          }
          else{ prec=NULL;
                delete p;
             }

       }



    }
}
void chainage_arr(elemt *&tete)
{
    elemt *p,*q;
    if(tete!=NULL)
    {p=tete;
    tete->prec=NULL;
    while(p->suiv!=NULL)
    {  q=p;
        p=p->suiv;
        p->prec=q;
    }
     }

}
void affich_de_sense(elemt *tete,bool choix)
{   elemt *p=tete;

    if(choix)
    {
    cout<<"--------------------------------------------\n";
      while(p!=NULL)
      {
          cout<<p->val<<endl;
          p=p->suiv;
      }
    cout<<"--------------------------------------------\n";

    }
    else{
        while(p->suiv!=NULL)
        {
            p=p->suiv;
        }
    cout<<"--------------------------------------------\n";
       while(p!=NULL)
       {
           cout<<p->val<<endl;
           p=p->prec;
       }
    cout<<"--------------------------------------------\n";
        }

}
elemt* acces_valeur(elemt *tete,int val)
{
  elemt *p;
  p=tete;
  while((p!=NULL)&&(p->val!=val))
  {
      p=p->suiv;
   }
  return p;
}
void insrtdc_element(elemt *&tete,int val)
{
    elemt *p,*nov;
    p=acces_valeur(tete,val);
    if(p!=NULL)
    {
        nov=(elemt*)malloc(sizeof(elemt));
        cout<<"donner la valeur de l element inserit:\n";
        cin>>nov->val;
        nov->suiv=p;
        nov->prec=p->prec;
        if(p->prec!=NULL)
            p->prec->suiv=nov;
        else
            tete=nov;
        p->prec=nov;
    }else
      cout<<"vous pouvez pas inserit!!!!!!\n";
}
void suprdc_par_valeur(elemt *&tete,int val)
{ elemt *p;
   p=acces_valeur(tete,val);
   if(p!=NULL)
   {
      if(p=tete)
        {tete=tete->suiv;
        tete->prec=NULL;
        }
      else
        p->prec->suiv=p->suiv;
      if(p->suiv==NULL)
        p->prec->suiv=NULL;
      else
        p->suiv->prec=p->prec;
    delete p;
    cout<<"l element a ete supprimer avec succes!!!\n";
   }

}

int main()
{    int choix;
     elemt *tete=NULL;
    int taill;
    cout<<"donner le nombre des elements: ";
    cin>>taill;
    cree_list(tete,taill);
    chainage_arr(tete);

        cout<<"-----------------------MENU-------------------\n";
        cout<<"1.affichage d une liste\n";
        cout<<"2.la taille d une liste\n";
        cout<<"3.comptage d'occurrence\n";
        cout<<"4.vérification si une liste est trie\n";
        cout<<"5.insertion en tete\n";
        cout<<"6.insertion en queue\n";
        cout<<"7.insertion un element dans liste dc\n";
        cout<<"8.suppression une valeur donnee\n";
        cout<<"9.suppression d une liste\n";
        cout<<"10.acces a une position donnee\n";
        cout<<"11.Quiter\n";
        cout<<"-----------------------------------------------------"<<endl;

    do{
        cout<<"donner votre choix:\n";
        cin>>choix;
        switch(choix)
        {
            case 1:{ cout<<"donner votre sense d affichage:\n";
                     cout<<"1 pour sense direct.\n sinon sense contraire.\n";
                     int ch;
                     cin>>ch;
                     if(ch==1)
                      affich_de_sense(tete,true);
                      else
                        affich_de_sense(tete,false);};break;
            case 2:cout<<"la taille de la liste est: "<<taill_liste(tete)<<" \n";break;
            case 3:{int v;
                    cout<<"donner la valeur qui vous voulez savoir sa nb d occurence:";
                    cin>>v;
                    cout<<"le nb d occurrence de "<<v<<" est: "<<nb_occ(tete,v)<<endl;};break;
            case 4:{if(si_trie(tete))
                    cout<<"la liste est trie!!\n";
                    else{
                    cout<<"la liste n est pas trie!!\n";
                    }
                    };break;
            case 5:{ int valeur;
                     cout<<"donner la valeur qui vous devez inserit:";
                     cin>>valeur;
                     insrt_tete(tete,valeur);};break;
            case 6:{ int valeur;
                      cout<<"donner la valeur qui vous voulez inserit\n";
                      cin>>valeur;
                      insrt_queue(tete,valeur);
                    };break;
            case 7:{ int val;
                     cout<<"donner la valeur qui vous voulez inserit avant elle: ";
                     cin>>val;
                      insrtdc_element(tete,val);

                    };break;
             case 8:{ cout<<"donner la valeur qui vous voulez supprimer:"<<endl;
                      int valeur;
                      cin>>valeur;
                       suprdc_par_valeur(tete,valeur);
                      };break;

            case 9:supprimer_liste(tete);break;
            case 10:{cout<<"donner une position qui vous voulez acceder: ";
                      int pos;elemt *s=NULL;
                      cin>>pos;
                      s=acces_pos(tete,pos);
                      if(s==NULL)
                       cout<<"l element n existe pas!!!!!!\n";
                      else
                        cout<<"la valeur d element rechercher est"<<s->val<<endl;
                      };break;
            case 11:{supprimer_liste(tete);
                     cout<<"fin de programme a bientot!!!!!"<<endl;break;
                     }


    }
    }while(choix!=11);

    system("pause");
    return 0;
}
