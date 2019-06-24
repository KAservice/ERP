#include "vcl.h"
#pragma hdrstop  
#include "UDisplayPokCF.h"   
#include "UDisplayPokImpl.h"  
#include "IDisplayPok.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDisplayPokCF::TDisplayPokCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDisplayPokCF::~TDisplayPokCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDisplayPokCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();
return result;  
}   
//---------------------------------------------------------------
int TDisplayPokCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDisplayPokCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDisplayPokCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDisplayPokImpl * ob=new TDisplayPokImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
