'use strict';

//Importar librerías de los modulos de JavaScript y para los controles
import * as THREE from "/build/three.module.js";
import { OrbitControls } from "/jsm/controls/OrbitControls.js";

//variables Globales
var container;
var escenaAncho, escenaAlto;
var escena;
var renderer;
var camara;
var controles;
var icosaedro;
var cubo;
//var flag;

// La función init () se usa para inicializar toda la página web
init();

function init() {
    crearEscena();
    update();
}

function crearEscena() {
    /*
    La propiedad innerWidth devuelve el ancho del área de contenido de una ventana.

    La propiedad innerHeight devuelve la altura del área de contenido de una ventana.
    */
    escenaAncho = window.innerWidth;
    escenaAlto = window.innerHeight;
    
    //Escena
    escena = new THREE.Scene();
    // Clase para cargar una textura de cubo. Esto utiliza el ImageLoader internamente para cargar archivos.
    var cieloCaja = new THREE.CubeTextureLoader().load( [

        '../assets/CieloCaja/cieloCaja_derecha.jpg',
        '../assets/CieloCaja/cieloCaja_izquierda.jpg', 
        '../assets/CieloCaja/cieloCaja_arriba.jpg',
        '../assets/CieloCaja/cieloCaja_abajo.jpg',
        '../assets/CieloCaja/cieloCaja_atras.jpg',
        '../assets/CieloCaja/cieloCaja_frente.jpg' 

    ] );

    escena.background = cieloCaja;

    //Render
    // El renderizador de WebGL muestra sus escenas bellamente diseñadas usando WebGL.
    renderer = new THREE.WebGLRenderer({antialias:true, alpha:true});
    /*
    La interfaz devicePixelRatio of Window devuelve la relación de la resolución en píxeles físicos 
    a la resolución en píxeles CSS para el dispositivo de visualización actual.
    En términos más simples, esto le dice al navegador cuántos píxeles reales de la pantalla deben usarse 
    para dibujar un solo píxel CSS.
    */
    renderer.setPixelRatio(window.devicePixelRatio);
    renderer.setSize(escenaAncho, escenaAlto);

    //Canvas
    /*
    El método getElementById () devuelve el elemento que tiene el atributo ID con el valor especificado.

    Este método es uno de los más comunes en HTML DOM y se usa casi cada vez que desea manipular u obtener 
    información de un elemento de su documento.
    */
    container = document.getElementById('container');
    container.appendChild(renderer.domElement );


    //Camara
    /*
    Una PerspectiveCamera define su tronco basado en 4 propiedades. near define dónde comienza el frente 
    del tronco. far define dónde termina. fov, el campo de visión, define qué tan alto es el frente y la
    parte posterior del tronco calculando la altura correcta para obtener el campo de visión especificado en 
    unidades cercanas de la cámara. El aspect define qué tan anchos son el anverso y el reverso del tronco. 
    El width del tronco es solo la altura multiplicada por el aspecto.
    */
    camara = new THREE.PerspectiveCamera( 30, escenaAncho / escenaAlto, 1, 10000);
    camara.position.set(100, 50, 500);

    //Luces

    var luz = new THREE.DirectionalLight(0xffffff);
    luz.position.set(1, 0, 10);
    escena.add(luz);

    /*
    Una fuente de luz colocada directamente sobre la escena, con un color que se desvanece del color del 
    cielo al color del suelo.

    HemisphereLight( skyColor : Integer, groundColor : Integer, intensity : Float )

        skyColor: (opcional) color hexadecimal del cielo. El valor predeterminado es 0xffffff.
        groundColor - (opcional) color hexadecimal del suelo. El valor predeterminado es 0xffffff.
        intensity: valor numérico (opcional) de la intensidad / intensidad de la luz. El valor predeterminado es 1.
    */
    var hemi = new THREE.HemisphereLight(0xffffff, 0xffffff, 0.5);
    hemi.position.set(0, 0, 5);
    escena.add(hemi);

    //Controles
    /*
    Una cámara de órbita es aquella que permite al usuario rotar alrededor de un punto central, pero manteniendo 
    bloqueado un eje en particular. Esto es extremadamente popular porque evita que la escena se "incline" fuera 
    del eje. Esta versión bloquea el eje Y (vertical) y permite a los usuarios orbitar, hacer zoom y desplazarse 
    con los botones izquierdo, central y derecho del mouse (o eventos táctiles específicos).
    */
    controles = new OrbitControls(camara, renderer.domElement);
    controles.update();

    /*
    IcosahedronGeometry
    Una clase para generar una geometría de icosaedro.
    197/5000
    radio: el valor predeterminado es 1.
    detail: el valor predeterminado es 0. Establecer esto en un valor mayor que 0 agrega más vértices y deja de 
    ser un icosaedro. Cuando el detalle es mayor que 1, es efectivamente una esfera.
    */
    //Crear Sol
    /*
    MeshLambertMaterial
    Un material para superficies no brillantes, sin reflejos especulares.

    parámetros: (opcional) un objeto con una o más propiedades que definen la apariencia del material. 
    Aquí se puede transferir cualquier propiedad del material (incluida cualquier propiedad heredada del Material).

    La excepción es el color de la propiedad, que se puede pasar como una cadena hexadecimal y es 0xffffff (blanco) 
    de forma predeterminada. Color.set (color) se llama internamente.
    */
    var icosaedroGeo = new THREE.IcosahedronGeometry(100, 1);
    icosaedroGeo.computeFlatVertexNormals();
    var icosaedroMaterial = new THREE.MeshLambertMaterial({color: 0xFF4D00});
    icosaedro = new THREE.Mesh(icosaedroGeo, icosaedroMaterial);
    icosaedro.position.z -= 500;
    escena.add(icosaedro);
    crearPlano()

    /*
    BoxGeometry es una clase de geometría para un cuboide rectangular con un 'ancho', 'altura' y 'profundidad' dados. 
    En la creación, el cuboide se centra en el origen, con cada borde paralelo a uno de los ejes.
    */
    // Crear el satélite
    var cuboGeo = new THREE.BoxGeometry(30, 30, 30);
    var cuboMaterial = new THREE.MeshBasicMaterial({color: 0xBBBBBB});
    cubo = new THREE.Mesh(cuboGeo, cuboMaterial);
    cubo.position.y = 500;
    escena.add(cubo);

}

// Funcion para crear los dos planos 
function crearPlano() {

    /*
    Esto es casi idéntico a un Object3D. Su propósito es hacer que trabajar con grupos de objetos 
    sea sintácticamente más claro.
    */
    var grupo = new THREE.Group();
    /*
    Una clase para generar geometrías planas
    ancho: ancho a lo largo del eje X. El valor predeterminado es 1.
    height: altura a lo largo del eje Y. El valor predeterminado es 1.
    ancho Segmentos - Opcional: El valor predeterminado es 1.
    Alto Segmentos - opcional: El valor predeterminado es 1
    */
    const planoRojito = new THREE.PlaneGeometry(1200, 1200, 1, 1);
    const planoGeo = new THREE.PlaneGeometry(1000, 1000, 32, 32);
    planoRojito.rotateX(-Math.PI / 2);
    planoGeo.rotateX(-Math.PI / 2);
    var vertices = planoGeo.vertices;

    for( let i = 0; i < vertices.length; i++) {

        vertices[i].y  = (Math.random() > 0.8) ? Math.random() * 100 : 0;

    }

    planoGeo.faces.forEach((value) => {

        const i = planoGeo.vertices[value.a];
        const j = planoGeo.vertices[value.b];
        const k = planoGeo.vertices[value.c];

        const maximo = Math.max(i.y, j.y, k.y);

        if( maximo > 1 ) return value.color.set( 0x00ccaf);
        value.color.set(0xff0000);

    } );

    planoGeo.verticesNeedUpdate = true;
    planoGeo.colorsNeedUpdate = true;

    /*
    Un material para dibujar geometrías de forma simple sombreada (plana o de alambre).

    Este material no se ve afectado por las luces.
    */
    const material = new THREE.MeshBasicMaterial( { vertexColors: THREE.VertexColors, wireframe: true});
    const material2 = new THREE.MeshBasicMaterial( { color: 0x200000} );

    var mesh = new THREE.Mesh( planoGeo, material );

    grupo.add( new THREE.Mesh( planoRojito, material2 ) );
    grupo.add( mesh );
    escena.add( grupo );
}

function update() {
    /*
    requestAnimationFrame informa al navegador que quieres realizar una animación y solicita que el navegador 
    programe el repintado de la ventana para el próximo ciclo de animación. El método acepta como argumento 
    una función a la que llamar antes de efectuar el repintado.
    */
    requestAnimationFrame( update );
    render();
}

function render() {
    controles.update();
    camara.position.z += Math.sin(Math.cos( 10 ) ) / 10;
    camara.position.x += Math.cos( Math.sin( 10 ) ) / 10;

    cubo.rotation.y += 0.1;
    cubo.rotation.x += 0.01;
    cubo.rotation.z += 0.001;

    /*
    flag = true;
    if(flag) {
        cubo.position.x ++;
        if(cubo.position.x == 10) {
            flag = false;
        }
    } else {
        cubo.position.x--;
        if(cubo.position.x == 0) {
            flag = true;
        }
    }
    */

    camara.lookAt(icosaedro.position)
    console.log(renderer.info.render.calls);
    renderer.render(escena, camara);
}
