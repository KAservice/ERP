#ifndef UREM_FormaElementaSprTrebUslovCFH                  
#define UREM_FormaElementaSprTrebUslovCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprTrebUslovCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprTrebUslovCF();                                                           
   ~TREM_FormaElementaSprTrebUslovCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
