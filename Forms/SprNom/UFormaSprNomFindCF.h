#ifndef UFormaSprNomFindCFH                  
#define UFormaSprNomFindCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSprNomFindCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSprNomFindCF();                                                           
   ~TFormaSprNomFindCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
