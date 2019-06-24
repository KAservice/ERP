#ifndef UFormaElementaSprImportNomCFH                  
#define UFormaElementaSprImportNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprImportNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprImportNomCF();                                                           
   ~TFormaElementaSprImportNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
